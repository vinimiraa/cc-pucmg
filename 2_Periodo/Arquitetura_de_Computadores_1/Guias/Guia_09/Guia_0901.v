// ------------------------- 
// Guia_0901.v  
// Test Clock Generator (2) 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

module clock ( output clk ); 
    reg clk; 
    
    initial begin : start
        clk = 1'b0; 
    end // start
    
    always begin  : clock
        #12 clk = ~clk; 
    end // clock
endmodule // clock ( )

module pulse ( signal, clock ); 
    input  clock; 
    output signal; 
    reg    signal; 
    
    always @ ( clock ) 
    begin : pulse
            signal = 1'b1; 
        #3  signal = 1'b0; 
        #3  signal = 1'b1; 
        #3  signal = 1'b0; 
    end // pulse
endmodule // pulse ( ) 

module trigger ( signal, on, clock ); 
    input  on, clock; 
    output signal; 
    reg    signal; 

    always @ ( posedge clock & on ) 
    begin : trigger
        #60 signal = 1'b1; 
        #60 signal = 1'b0; 
    end //trigger
endmodule // trigger ( )

module Guia_0901;
    // instancia do clock
    wire   clock; 
    clock clk ( clock ); 
    // instancia do pulse
    wire  p1;
    pulse   pulse1  ( p1, clock ); 
    // instancia do trigger
    reg   p; 
    wire  t1; 
    trigger trigger1 ( t1, p, clock ); 
    
    initial begin : start
        p = 1'b0; 
    end // start

    initial begin : main
        $dumpfile ( "Guia_0901.vcd" ); 
        $dumpvars ( 1, clock, p1, p, t1 ); 
        // $monitor ( "clock = %b  //  pulse = %b  //  p = %b , trigger = %b", clock, p1, p, t1 );
        #060 p = 1'b1; 
        #120 p = 1'b0; 
        #180 p = 1'b1; 
        #240 p = 1'b0; 
        #300 p = 1'b1; 
        #360 p = 1'b0; 
        #376 $finish; 
    end // main
endmodule // Guia_0901 ( )