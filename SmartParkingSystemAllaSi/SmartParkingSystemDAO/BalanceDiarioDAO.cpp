#include "pch.h"
#include "BalanceDiarioDAO.h"

using namespace SmartParkingSystemDAO;
using namespace System::IO;
using namespace SmartParkingSystemModel;

BalanceDiarioDAO::BalanceDiarioDAO() {
    this->nombreArchivo = "BalancesDiarios.txt"; // Inicializamos el nombre del archivo
}

List<BalanceDiario^>^ BalanceDiarioDAO::buscarTodosArchivo() {
    List<BalanceDiario^>^ lista = gcnew List<BalanceDiario^>();
    if (!File::Exists(this->nombreArchivo)) return lista;

    for each (String ^ line in File::ReadAllLines(this->nombreArchivo)) {
        if (String::IsNullOrWhiteSpace(line)) continue;
        array<String^>^ parts = line->Split(';');

        // Mapeo en el orden exacto en que se guardan
        DateTime fecha = parts->Length > 0 ? DateTime::Parse(parts[0]) : DateTime::MinValue;
        double saldoIni = parts->Length > 1 ? Convert::ToDouble(parts[1]) : 0.0;
        double saldoFin = parts->Length > 2 ? Convert::ToDouble(parts[2]) : 0.0;
        double ingresos = parts->Length > 3 ? Convert::ToDouble(parts[3]) : 0.0;
        double egresos = parts->Length > 4 ? Convert::ToDouble(parts[4]) : 0.0;
        int turnos = parts->Length > 5 ? Convert::ToInt32(parts[5]) : 0;

        BalanceDiario^ b = gcnew BalanceDiario(fecha, saldoIni, saldoFin, ingresos, egresos, turnos);
        lista->Add(b);
    }
    return lista;
}

BalanceDiario^ BalanceDiarioDAO::buscarPorFechaArchivo(DateTime fecha) {
    List<BalanceDiario^>^ lista = buscarTodosArchivo();
    for each (BalanceDiario ^ b in lista) {
        if (b->getFecha().Date == fecha.Date) {
            return b;
        }
    }
    return nullptr;
}

void BalanceDiarioDAO::registrarBalanceArchivo(BalanceDiario^ nuevoBalance) {
    try {
        // Guardamos los 6 campos en orden estricto
        String^ nuevaLinea = String::Format("{0};{1};{2};{3};{4};{5}",
            nuevoBalance->getFecha().ToString("yyyy-MM-dd HH:mm:ss"),
            nuevoBalance->getTotalSaldoInicialTurnos(),
            nuevoBalance->getTotalSaldoFinalTurnos(),
            nuevoBalance->getTotalIngresosMovimientos(),
            nuevoBalance->getTotalEgresosMovimientos(),
            nuevoBalance->getCantidadTurnos()
        );

        StreamWriter^ writer = gcnew StreamWriter(this->nombreArchivo, true);
        writer->WriteLine(nuevaLinea);
        writer->Close();
    }
    catch (Exception^ ex) {
        throw gcnew Exception("Error al guardar el balance diario: " + ex->Message);
    }
}

void BalanceDiarioDAO::eliminarBalanceArchivo(DateTime fecha) {
    List<BalanceDiario^>^ lista = buscarTodosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getFecha().Date == fecha.Date) {
            lista->RemoveAt(i);
            break;
        }
    }
    escribirArchivo(lista);
}

void BalanceDiarioDAO::escribirArchivo(List<BalanceDiario^>^ listaBalances) {
    List<String^>^ lines = gcnew List<String^>();
    for each (BalanceDiario ^ b in listaBalances) {
        String^ l = String::Format("{0};{1};{2};{3};{4};{5}",
            b->getFecha().ToString("yyyy-MM-dd HH:mm:ss"),
            b->getTotalSaldoInicialTurnos(),
            b->getTotalSaldoFinalTurnos(),
            b->getTotalIngresosMovimientos(),
            b->getTotalEgresosMovimientos(),
            b->getCantidadTurnos()
        );
        lines->Add(l);
    }
    File::WriteAllLines(this->nombreArchivo, lines->ToArray());
}