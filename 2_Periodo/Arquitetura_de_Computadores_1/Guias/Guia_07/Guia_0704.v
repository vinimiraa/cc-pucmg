// ------------------------- 
// Guia_0704 - GATES 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  f0704 - GATES
// ------------------------- 
module f0704_xor( output a, output b, input x, input y );
    xor  XOR1  ( a, x, y ); // saida do XOR
    xnor XNOR1 ( b, x, y ); // saida do XNOR
endmodule // f0704

// ------------------------- 
//  f0704 - GATES 
// ------------------------- 
module f0704_or( output a, output b, input x, input y );
    or  OR1  ( a, x, y ); // saida do OR
    nor NOR1 ( b, x, y ); // saida do NOR
endmodule // f0704

// ------------------------- 
//  Multiplexador com 2 bits para Selecao
// ------------------------- 
module mux ( output z, 
             input  a, input  b, input c, input d, 
             input select1, input select2 
           ); 
    // definir dados locais 
    wire not_select1; 
    wire not_select2; 
    wire sa; 
    wire sb; 
    wire sc; 
    wire sd; 
    // descrever por portas 
    not  NOT1 ( not_select1, select1 ); 
    not  NOT2 ( not_select2, select2 ); 
    and AND1 ( sa, a, not_select1, not_select2 ); 
    and AND2 ( sb, b, not_select1, select2 ); 
    and AND3 ( sc, c, select1, not_select2 ); 
    and AND4 ( sd, d, select1, select2 ); 
    or  OR1  ( z, sa, sb, sc, sd ); 
endmodule // mux 

// ------------------------- 
//  Guia_0704 - Modulo de Teste 
// -------------------------
module Guia_0704; 
    // ------------------------- definir dados 
    reg  x = 0, y = 0; // inputs
    reg  s1 = 0;       // input selecionavel
    reg  s2 = 0;       // input selecionavel
    wire z;            // output MUX
    wire a, b;         // output XOR/XNOR
    wire c, d;         // output OR/NOR
    integer i = 0;

    // instancias
    f0704_xor XOR1 ( a, b, x, y );
    f0704_or  OR1  ( c, d, x, y );
    mux MUX1( z, c, d, a, b, s1, s2 );

    // valores iniciais 
    initial begin: start 
        x=1'b0; y=1'b0; s1=1'b0; s2=1'b0;
    end // start
    
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0704 - Teste"); 
        $display("LU's module:");
        $display( "   x    y   OR   NOR  XOR XNOR  s1   s2   MUX" );
        $monitor("%4b %4b %4b %4b %4b %4b %4b %4b %4b ", x, y, c, d, a, b, s1, s2, z ); 
        for (i = 0; i < 4; i = i + 1) begin
            { x, y } = i;
            { s1, s2 } = i;
            #1;
        end // for
    end // main 
endmodule // Guia_0704 