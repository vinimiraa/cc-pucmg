// ------------------------- 
// Guia_0703 - GATES 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  f0703 - GATES
// ------------------------- 
module f0703_and( output a, output b, input x, input y );
    and  AND1  ( a, x, y ); // saida do AND
    nand NAND1 ( b, x, y ); // saida do NAND
endmodule // f0703

// ------------------------- 
//  f0703 - GATES 
// ------------------------- 
module f0703_or( output a, output b, input x, input y );
    or  OR1  ( a, x, y ); // saida do OR
    nor NOR1 ( b, x, y ); // saida do NOR
endmodule // f0703

// ------------------------- 
//  multiplexer 
// ------------------------- 
module mux ( output z, input  a, input  b, input  select ); 
    // definir dados locais 
    wire not_select; 
    wire sa; 
    wire sb; 
    // descrever por portas 
    not NOT1 ( not_select, select ); 
    and AND1 ( sa, a, not_select ); 
    and AND2 ( sb, b, select ); 
    or  OR1  ( z, sa, sb ); 
endmodule // mux 

// ------------------------- 
//  Guia_0703 - Modulo de Teste 
// -------------------------
module Guia_0703; 
    // ------------------------- definir dados 
    reg  x = 0, y = 0; // inputs
    reg  s1 = 0;       // input selecionavel
    reg  s2 = 0;       // input selecionavel
    reg  s3 = 0;       // input selecionavel
    wire z1, z2, z3;   // output MUX
    wire a, b;         // output AND/NAND
    wire c, d;         // output OR/NOR
    integer i = 0;

    // instancias
    f0703_and AND ( a, b, x, y );
    f0703_or  OR  ( c, d, x, y );
    mux MUX1 ( z1, a, b, s1 ); // mux do AND/NAND
    mux MUX2 ( z2, c, d, s2 ); // mux do OR/NOR
    mux MUX3 ( z3, z1, z2, s3 ); // mux do AND/NAND / OR/NOR

    // valores iniciais 
    initial begin: start 
        x=1'b0; y=1'b0; s1=1'b0; s2=1'b0; s3=1'b0;
    end // start
    
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0703 - Teste"); 
        $display("LU's module:");
        $display( "   x    y   AND NAND  s1   OR   NOR  s2   MUX1 MUX2 s3   MUX3 " );
        $monitor("%4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b", x, y, a, b, s1, c, d, s2, z1, z2, s3, z3 ); 
        for (i = 0; i < 4; i = i + 1) begin
            { x, y } = i;
            #1;
        end // for
    end // main 
endmodule // Guia_0703 