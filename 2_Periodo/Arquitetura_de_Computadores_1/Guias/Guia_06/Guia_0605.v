// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839
// --------------------- 

// --------------------- 
// Expressoes
// --------------------- 

module g0605 ( output s1,
               output s2,
               input  x, y, z ); // mintermos 
    assign s1 = ( ( ~(~x|~y) & ~(x&y) ) | ~( (y&z) | ~x ) ); // expressao 
    assign s2 = (x&~z) | (x&~y);                             // expressao simplificada
endmodule // g0605

module f0605 ( output s, 
               input x, 
               input y,
               input z ); 
    // definir dado local   
    wire not_y; 
    wire not_z; 
    wire s1,s2;
    // descrever por portas
    not NOT1 (not_y, y);
    not NOT2 (not_z, z);
    and AND1 (s1, x, not_z);
    and AND2 (s2, x, not_y);
    or  OR   (s, s1, s2);
endmodule // f0605

// --------------------- 
// Guia_0605 
// --------------------- 

module Guia_0605; 
    reg   x = 0, y = 0, z = 0; 
    wire  s1, s2; 
    integer i = 0; 
    // instancias 
    g0605 EXP (s1, s2, x, y, z); 
    f0605 CIR (s3, x, y, z);
    // valores iniciais 
    initial begin: start 
        x=1'bx; y=1'bx; z=1'bx;   // indefinidos 
    end // start

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0605 - Teste ");  
        
        // monitoramento 
        $display("\nExpressao:");
        $display(" x  y  z = s1"); 
        $monitor("%2b %2b %2b = %2b", x, y, z, s1 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // for

        $display("\nExpressao simplificada:");
        $display(" x  y  z = s2"); 
        $monitor("%2b %2b %2b = %2b", x, y, z, s2 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // for

        $display("\nExpressao simplificada feita com Circuito:");
        $display(" x  y  z = s3"); 
        $monitor("%2b %2b %2b = %2b", x, y, z, s3 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // for

    end // main

endmodule // Guia_0605 