// ------------------------- 
// Guia_0800 - FULL ADDER 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  half adder 
// ------------------------- 
module halfAdder ( output carry, output sum, input a, input b ); 
    // descrever por portas 
    xor XOR1 ( sum, a, b ); 
    and AND1 ( carry, a, b ); 
endmodule // halfAdder 

// ------------------------- 
//  full adder 
// ------------------------- 
module fullAdder ( output carry, output sum, input a,  input b,  input carryIn ); 
    // descrever por portas e/ou modulos 
    wire w1,w2,w3;
    halfAdder HA0 ( w1, w2, a, b );
    halfAdder HA1 ( w3, sum, w2, carryIn );
    or OR1 ( carry, w1, w3 );
endmodule // fullAdder 

// ------------------------- 
//  Guia_0800 
// ------------------------- 
module Guia_0800; 
    // ------------------------- definir dados 
    reg  [2:0] x; 
    reg  [2:0] y; 
    wire [2:0] carry; // “vai-um” 
    wire [3:0] soma; 

    // halfAdder HA0 ( carry[0], soma[0], x[0], y[0] ); 
    fullAdder FA0 ( carry[0], soma[0], x[0], y[0], 1'b0     ); 
    fullAdder FA1 ( carry[1], soma[1], x[1], y[1], carry[0] ); 
    fullAdder FA2 ( carry[2], soma[2], x[2], y[2], carry[1] ); 
    assign soma[3] = carry[2];    
    
    // Atribuindo valores
    initial begin : start
        x = 3'b000;
        y = 3'b000;
    end // start

    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0800 - Vinicius Miranda de Araujo - 812839"); 
        $display("Test ALU’s full adder"); 
        // projetar testes do somador completo 
        $display( " x  +  y  = soma" );
        $monitor( "%b + %b = %b", x, y, soma );
        for( integer i = 0; i < 8; i++ ) begin
            { x } = i;
            { y } = i;
            #1;
        end // for
    end // main
endmodule // Guia_0800 