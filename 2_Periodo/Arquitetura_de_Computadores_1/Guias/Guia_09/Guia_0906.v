// ------------------------- 
// Guia_0906.v
// Test Clock Generator (7) 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

`include "clock.v" 

module pulse1 ( signal, clock ); 
    input  clock; 
    output signal; 
    reg    signal; 
    
    always @ ( negedge clock ) 
    begin : pulse
        #21  signal = 1'b1;
        #3  signal = 1'b0;            
        #21  signal = 1'b1;
        #3  signal = 1'b0;            
        #21  signal = 1'b1;
        #3  signal = 1'b0;            
    end // end pulse
endmodule // pulse ( )

module Guia_0906; 
    wire  clock; 
    clock clk ( clock ); 
    
    wire  p1; 
    pulse1 pls1 ( p1, clock ); 
    
    initial begin : main 
        $dumpfile ( "Guia_0906.vcd" ); 
        $dumpvars ( 1, clock, p1 ); 
        
        #480 $finish; 
    end // main
endmodule // Guia_0906 ( )