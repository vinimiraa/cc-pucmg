// ------------------------- 
// Guia_0705 - GATES 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  f0705 - GATES
// ------------------------- 
module f0705( output a, output b, output c, output d, output e, output f, output g, output h,
              input x, input y 
            );
    not  NOT1  (  a , x  ); // saida do NOT_X
    not  NOT2  (  b , y  ); // saida do NOT_Y
    and  AND1  ( c, x, y ); // saida do AND
    nand NAND1 ( d, x, y ); // saida do NAND
    or   OR1   ( e, x, y ); // saida do OR
    nor  NOR1  ( f, x, y ); // saida do NOR
    xor  XOR1  ( g, x, y ); // saida do XOR
    xnor XNOR1 ( h, x, y ); // saida do XNOR
endmodule // f0705

// ------------------------- 
//  Multiplexador com 3 bits para Selecao
// ------------------------- 
module mux ( output z, 
             input a, input b, input c, input d, input e, input f, input g, input h,
             input select1, input select2, input select3 
           ); 
    // definir dados locais 
    wire not_select1, not_select2, not_select3; 
    wire sa, sb, sc, sd, se, sf, sg, sh; 
    // descrever por portas 
    not NOT1 ( not_select1, select1 ); 
    not NOT2 ( not_select2, select2 ); 
    not NOT3 ( not_select3, select3 ); 
    and AND1 ( sa, a, not_select1, not_select2, not_select3 ); 
    and AND2 ( sb, b, not_select1, not_select2,     select3 ); 
    and AND3 ( sc, c, not_select1,     select2, not_select3 ); 
    and AND4 ( sd, d, not_select1,     select2,     select3 ); 
    and AND5 ( se, e,     select1, not_select2, not_select3 ); 
    and AND6 ( sf, f,     select1, not_select2,     select3 ); 
    and AND7 ( sg, g,     select1,     select2, not_select3 ); 
    and AND8 ( sh, h,     select1,     select2,     select3 ); 
    or  OR1  ( z, sa, sb, sc, sd, se, sf, sg, sh ); 
endmodule // mux 

// ------------------------- 
//  Guia_0705 - Modulo de Teste 
// -------------------------
module Guia_0705; 
    // ------------------------- definir dados 
    reg  x = 0, y = 0; // inputs
    reg  s1 = 0;       // input selecionavel
    reg  s2 = 0;       // input selecionavel
    reg  s3 = 0;       // input selecionavel
    wire z;            // output MUX
    wire a, b;         // output NOT_X/NOT_Y
    wire c, d;         // output AND/NAND
    wire e, f;         // output OR/NOR
    wire g, h;         // output XOR/XNOR
    integer i = 0;

    // instancias
    f0705 GATES ( a, b, c, d, e, f, g, h, x, y );
    mux MUX1( z, a, b, c, d, e, f, g, h, s1, s2, s3 );

    // valores iniciais 
    initial begin: start 
        x=1'b0; y=1'b0; s1=1'b0; s2=1'b0; s3=1'b0;
    end // start
    
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0705 - Teste"); 
        $display("LU's module:");
        $display( "   x    y   NOTX NOTY AND NAND  OR   NOR  XOR XNOR  s1   s2   S3   MUX" );
        $monitor("%4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b", x, y, a, b, c, d, e, f, g, h, s1, s2, s3, z ); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y } = i;
            { s1, s2, s3 } = i;
            #1;
        end // for
    end // main 
endmodule // Guia_0705 