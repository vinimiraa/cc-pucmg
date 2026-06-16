// ------------------------------
// --- Memória RAM 2x8
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// -----------------------------

`include "ram1x8.v"
`include "mux16x1.v"
`include "demux1x2.v"

module ram2x8 ( output o1, output o2, output o3, output o4, output o5, output o6, output o7, output o8,
                input address, input rw, input clock, input clear,
                input i1, input i2, input i3, input i4, input i5, input i6, input i7, input i8 );

    // variavies
    reg  x = 1;
    wire dm1, dm2;
    wire o1_1, o2_1, o3_1, o4_1, o5_1, o6_1, o7_1, o8_1;
    wire o1_2, o2_2, o3_2, o4_2, o5_2, o6_2, o7_2, o8_2;

    // descrição por portas lógicas
    demux1x2 DM1x2_1  ( dm1, dm2, x, address );

    ram1x8   RAM1x8_1 ( o1_1, o2_1, o3_1, o4_1, o5_1, o6_1, o7_1, o8_1,
                        dm1, rw, clock, clear,
                        i1, i2, i3, i4, i5, i6, i7, i8 );

    ram1x8   RAM1x8_2 ( o1_2, o2_2, o3_2, o4_2, o5_2, o6_2, o7_2, o8_2,
                        dm2, rw, clock, clear,
                        i1, i2, i3, i4, i5, i6, i7, i8 );
                        
    mux16x1  MUX_1    ( o1, o2, o3, o4, o5, o6, o7, o8,
                        o1_1, o2_1, o3_1, o4_1, o5_1, o6_1, o7_1, o8_1,
                        o1_2, o2_2, o3_2, o4_2, o5_2, o6_2, o7_2, o8_2, address );

endmodule // ram2x8