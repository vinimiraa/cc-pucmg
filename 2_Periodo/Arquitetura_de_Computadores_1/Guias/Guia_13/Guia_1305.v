// --------------------
// --- Guia_1305
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// --------------------

`include "tff.v"

module Guia_1305;
    reg clk, clear;
    reg L; // constante negativa

    tff TFF1 ( o1, qn1, clk, clk, L, clear );
    tff TFF2 ( o2, qn2, qn1, qn1, L, clear );
    tff TFF3 ( o3, qn3, qn2, qn2, L, clear );
    and AND1 ( clr1, o1, o2, o3 );

    initial begin : main
        $display ( "Guia_1305 - Teste" );
        $display ( " clk   output");
        // initial values
        clk   = 0;
        clear = 1;
        L     = 0;
        #5 clear = 0;
        #95
        $finish;
    end // main
        
    always
        #5 clk = ~clk;

    always @( posedge clk ) begin
        $display ( " %3d    %d%d%d", $time, o3, o2, o1 );
    end 
endmodule // Guia_1305