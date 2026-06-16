// ------------------------- 
// Guia_0904.v
// Test Clock Generator (5) 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

`include "clock.v" 

module pulse ( signal, clock ); 
    input  clock; 
    output signal; 
    reg    signal; 
    
    always @ ( clock ) 
    begin : pulse
            signal = 1'b1;
        #4  signal = 1'b0;
        #4  signal = 1'b1;
        #4  signal = 1'b0;  
        #4  signal = 1'b1;
        #4  signal = 1'b0;  
    end // end pulse
endmodule // pulse ( )

module Guia_0904; 
    wire  clock; 
    clock clk ( clock ); 
    
    wire  p1; 
    pulse pls1 ( p1, clock ); 
    
    initial begin : main 
        $dumpfile ( "Guia_0904.vcd" ); 
        $dumpvars ( 1, clock, p1 ); 
        
        #480 $finish; 
    end // main
endmodule // Guia_0904 ( )