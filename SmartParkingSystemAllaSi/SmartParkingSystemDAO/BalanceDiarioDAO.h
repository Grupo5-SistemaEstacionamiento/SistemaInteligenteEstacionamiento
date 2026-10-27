#pragma once

namespace SmartParkingSystemDAO {

    using namespace System::Collections::Generic;
    using namespace System;
    using namespace SmartParkingSystemModel;

    public ref class BalanceDiarioDAO {
    private:
        String^ nombreArchivo; 
    public:
        BalanceDiarioDAO();
        List<BalanceDiario^>^ buscarTodosArchivo();
        BalanceDiario^ buscarPorFechaArchivo(DateTime fecha);
        void registrarBalanceArchivo(BalanceDiario^ balance);
        void eliminarBalanceArchivo(DateTime fecha);
        void escribirArchivo(List<BalanceDiario^>^ listaBalances);
    };
}