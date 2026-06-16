// ------------------------- 
// Guia_0508
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  nand = ~( ~a & ~b )
//  Fazendo a tabela verdade para prever resultados.	
//  | a | b | ~(~a&~b)|
//  |---|---|---------|
//  | 0 | 0 |    0    |
//  | 0 | 1 |    1    |
//  | 1 | 0	|    1    |
//  | 1 | 1 |    1    |
// ------------------------- 

// ------------------------- 
// f1 - NOR
// ------------------------- 
module f1 ( output s, 
            input a, 
            input b ); 
    // definir dado local   
    wire not_a;
    wire not_b;
    wire not_s;
    // descrever por portas
    nand NAND1 (not_a, a, a);
    nand NAND2 (not_b, b, b);
    nand NAND3 (s, not_a, not_b );
endmodule // f1 

// ------------------------- 
// f2 - Expressao
// ------------------------- 
module f2 ( output s, 
            input a, 
            input b ); 
    // descrever por expressao 
    assign s = ~(~a & ~b); 
endmodule // f2 

module Guia_0508; 
    // ------------------------- definir dados 
    reg  x, y; 
    wire a, b; 
    f1 moduloA ( a, x, y ); 
    f2 moduloB ( b, x, y ); 
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0508 - Test\n"); 
        // projetar testes do modulo 
        $display(" x  y  a  b"); 
        $monitor("%2b %2b %2b %2b", x, y, a, b); 
           x = 1'b0; y = 1'b0; 
        #1 x = 1'b0; y = 1'b1; 
        #1 x = 1'b1; y = 1'b0; 
        #1 x = 1'b1; y = 1'b1; 
    end // end main 
endmodule // Guia_0508