// ------------------------- 
// Guia_0802 - FULL DIFFERENCE 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  half difference 
// ------------------------- 
module halfDiff ( output carry, output diff, input a, input b ); 
    // descrever por portas 
    wire not_a;
    not NOT0 ( not_a, a );
    xor XOR0 ( diff , a, b ); 
    and AND0 ( carry, not_a, b ); 
endmodule // halfDiff 

// ------------------------- 
//  full difference 
// ------------------------- 
module fullDiff ( output carry, output diff, input a,  input b,  input carryOut ); 
    // descrever por portas e/ou modulos 
    wire w1,w2,w3;
    halfDiff HD0 ( w1, w2, a, b );
    halfDiff HD1 ( w3, diff, w2, carryOut );
    or       OR1 ( carry, w1, w3 );
endmodule // fullDiff 

// ------------------------- 
//  Guia_0802 
// ------------------------- 
module Guia_0802; 
    // ------------------------- definir dados 
    reg  [5:0] x; 
    reg  [5:0] y; 
    wire [5:0] carry; // “vai-um” 
    wire [6:0] dif; 

    // Instancias
    fullDiff FD0 ( carry[0], dif[0], x[0], y[0], 1'b0     ); 
    fullDiff FD1 ( carry[1], dif[1], x[1], y[1], carry[0] ); 
    fullDiff FD2 ( carry[2], dif[2], x[2], y[2], carry[1] ); 
    fullDiff FD3 ( carry[3], dif[3], x[3], y[3], carry[2] ); 
    fullDiff FD4 ( carry[4], dif[4], x[4], y[4], carry[3] ); 
    fullDiff FD5 ( carry[5], dif[5], x[5], y[5], carry[4] ); 
    assign dif[6] = carry[5];    

    // Atribuindo valores
    initial begin : start
        x = 6'b000000;
        y = 6'b000000;
    end // start

    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0802 - Vinicius Miranda de Araujo - 812839"); 
        $display("Test ALU’s full difference");  
        $display( "  x   -   y   =   dif" );
        $monitor( "%b - %b = %b", x, y, dif );
        for( integer i = 0; i < 64; i++ ) begin
            { x } = i;
            { y } = i;
            #1;
        end // for
    end // main
endmodule // Guia_0802 