// ------------------------- 
// Guia_0500.v - GATES 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  f5_gate 
//  m  a  b  s 
//  0  0  0  0 
//  1  0  1  1 <- a'.b 
//  2  1  0  0 
//  3  1  1  0 
// 
// ------------------------- 
module f5a (output s, 
            input  a, 
            input  b ); 
    // definir dado local   
    wire not_a; 
    // descrever por portas 
    not NOT1 ( not_a, a ); 
    and AND1 ( s, not_a, b ); 
endmodule // f5a 

// ------------------------- 
//  f5_gate 
//  m  a  b  s 
//  0  0  0  0 
//  1  0  1  1 <- a'.b 
//  2  1  0  0 
//  3  1  1  0 
// 
// ------------------------- 
module f5b (output s, 
            input  a, 
            input  b ); 
    // descrever por expressao 
    assign s = ~a & b; 
endmodule // f5b 

module test_f5; 
    // ------------------------- definir dados 
    reg  x; 
    reg  y; 
    wire a, b; 
    f5a moduloA ( a, x, y ); 
    f5b moduloB ( b, x, y ); 
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0500 - xxx yyy zzz - 999999"); 
        $display("Test module"); 
        $display("   x     y    a    b"); 

        // projetar testes do modulo 
        $monitor("%4b %4b %4b %4b", x, y, a, b); 
        x = 1'b0;  y = 1'b0; 
        #1 x = 1'b0; y = 1'b1; 
        #1 x = 1'b1; y = 1'b0; 
        #1 x = 1'b1; y = 1'b1; 
    end // end main 
endmodule // test_f5