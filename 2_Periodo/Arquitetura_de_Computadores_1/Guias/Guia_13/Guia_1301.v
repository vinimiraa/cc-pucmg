// --------------------
// --- Guia_1301
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// --------------------

`include "jkff.v"

module Guia_1301;
    reg clk, clear;
    reg H; // constante positiva - high
    reg L; // constante negativa - low

    jkff JKFF1 ( t1, o6, H, H, clk, L, clear );
    jkff JKFF2 ( t2, o5, H, H, o6,  L, clear );
    jkff JKFF3 ( t3, o4, H, H, o5,  L, clear );
    jkff JKFF4 ( t4, o3, H, H, o4,  L, clear );
    jkff JKFF5 ( t5, o2, H, H, o3,  L, clear );
    jkff JKFF6 ( t6, o1, H, H, o2,  L, clear );

    initial begin : main
        $display ( "Guia_1301 - Teste" );
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
endmodule // Guia_1301