// ------------------------------
// --- Memória RAM 1x8
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// -----------------------------

`include "ram1x4.v"

module ram1x8 ( output o1, output o2, output o3, output o4, output o5, output o6, output o7, output o8,
                input address, input rw, input clock, input clear,
                input i1, input i2, input i3, input i4, input i5, input i6, input i7, input i8 );
    // descrição por portas lógicas
    ram1x4 RAM1x4_1 ( o1, o2, o3, o4, address, rw, clock, clear, i1, i2, i3, i4 );
    ram1x4 RAM1x4_2 ( o5, o6, o7, o8, address, rw, clock, clear, i5, i6, i7, i8 );
endmodule // ram1x8