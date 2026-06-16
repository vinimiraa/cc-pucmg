// ------------------------- 
// Guia_0900.v 
// Test Clock Generator (1) 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

module clock ( output clk ); 
    reg clk;
    
    initial begin : start
    clk = 1'b0; 
    end // start

    always begin : clock 
        #12 clk = ~clk; 
    end // clock
endmodule // clock ( ) 

module Guia_0900; 
    wire  clk; 
    clock CLK1 ( clk ); 
    
    initial begin : main 
        $dumpfile ( "Guia_0900.vcd" ); 
        $dumpvars; 
        #120 $finish; 
    end // main
endmodule // Guia_0901 ( )