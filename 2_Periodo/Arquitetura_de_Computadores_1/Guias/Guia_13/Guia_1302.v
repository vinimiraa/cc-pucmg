// --------------------
// --- Guia_1302
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// --------------------

`include "jkff.v"

module Guia_1302;
    reg clk, clear;
    reg H; // constante positiva
    reg L; // constante negativa

    jkff JKFF1 ( t1, s6, H, H, clk, L, clear );
    jkff JKFF2 ( t2, s5, H, H, s6,  L, clear );
    jkff JKFF3 ( t3, s4, H, H, s5,  L, clear );
    jkff JKFF4 ( t4, s3, H, H, s4,  L, clear );
    jkff JKFF5 ( t5, s2, H, H, s3,  L, clear );
    jkff JKFF6 ( t6, s1, H, H, s2,  L, clear );
    not  NOT_6 ( o6, s6 );
    not  NOT_5 ( o5, s5 );
    not  NOT_4 ( o4, s4 );
    not  NOT_3 ( o3, s3 );
    not  NOT_2 ( o2, s2 );
    not  NOT_1 ( o1, s1 );

    initial begin : main
        $display ( "Guia_1302 - Teste" );
        $display ( " clk    output");
        // initial values
        clk   = 1;
        H     = 1;
        L     = 0;
        clear = 1;
        #5 clear = 0;
        #650
        $finish;
    end // main
        
    always
        #5 clk = ~clk;

    always @( posedge clk ) begin
        $display ( " %3d    %d%d%d%d%d%d", $time, o1, o2, o3, o4, o5, o6 );
    end 
endmodule // Guia_1302