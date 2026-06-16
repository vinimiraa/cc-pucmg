// ------------------------------
// --- Memória RAM 1x4
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// -----------------------------

`include "jkff.v"

module ram1x4 (output o1, output o2, output o3, output o4,
                input address, input rw, input clock, input clear,
                input i1, input i2, input i3, input i4 );
    // variaveis
    wire ni1, ni2, ni3, ni4; // not_input
    wire newadr;       
    wire s1, s2, s3, s4;
    wire t;
    reg  preset = 0;

    // descriçao por portas lógicas
    not  NOT_1  ( ni1, i1 );
    not  NOT_2  ( ni2, i2 );
    not  NOT_3  ( ni3, i3 );
    not  NOT_4  ( ni4, i4 );
    and  AND_1  ( newadr, address, rw, clock );
    jkff JKFF_1 ( s1, t, i1, ni1, newadr, preset, clear );
    jkff JKFF_2 ( s2, t, i2, ni2, newadr, preset, clear );
    jkff JKFF_3 ( s3, t, i3, ni3, newadr, preset, clear );
    jkff JKFF_4 ( s4, t, i4, ni4, newadr, preset, clear );
    and  AND_2  ( o1, s1, address );
    and  AND_3  ( o2, s2, address );
    and  AND_4  ( o3, s3, address );
    and  AND_5  ( o4, s4, address );
endmodule // ram1x4