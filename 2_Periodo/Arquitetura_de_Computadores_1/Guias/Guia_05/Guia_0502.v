// ------------------------- 
// Guia_0502
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  (~a|b) -> nand = ~(a&~b) 
//  Fazendo a tabela verdade para prever resultados.	
//  | a | b | (~a|b)  |
//  |---|---|---------|
//  | 0 | 0 |    1    |
//  | 0 | 1 |    1    |
//  | 1 | 0	|    0    |
//  | 1 | 1 |    1    |
// ------------------------- 

// ------------------------- 
// f1 - NAND
// ------------------------- 
module f1 ( output s, 
            input a, 
            input b ); 
    // definir dado local   
    wire not_b; 
    // descrever por portas
    nand NAND1 (not_b, b, b);
    nand NAND2 (s, a, not_b);
endmodule // f1 

// ------------------------- 
// f2 - Expressao
// ------------------------- 
module f2 ( output s, 
            input a, 
            input b ); 
    // descrever por expressao 
    assign s = (~a | b); 
endmodule // f2 

module Guia_0502; 
    // ------------------------- definir dados 
    reg  x, y; 
    wire a, b; 
    f1 moduloA ( a, x, y ); 
    f2 moduloB ( b, x, y ); 
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0502 - Test\n"); 
        // projetar testes do modulo 
        $display(" x  y  a  b"); 
        $monitor("%2b %2b %2b %2b", x, y, a, b); 
           x = 1'b0; y = 1'b0; 
        #1 x = 1'b0; y = 1'b1; 
        #1 x = 1'b1; y = 1'b0; 
        #1 x = 1'b1; y = 1'b1; 
    end // end main 
endmodule // Guia_0502