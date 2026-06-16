// ------------------------- 
// Guia_0701 - GATES 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  f0701 - GATES 
// ------------------------- 
module f0701( output a, output b, input x, input y );
    and  AND1  ( a, x, y ); // saida do AND
    nand NAND1 ( b, x, y ); // saida do NAND
endmodule // f0701

// ------------------------- 
//  Multiplexador com 1 bit para Selecao 
// ------------------------- 
module mux ( output z, 
             input a, input b, 
             input select 
           ); 
    // definir dados locais 
    wire not_select; 
    wire sa; 
    wire sb; 
    // descrever por portas 
    not NOT1 ( not_select, select ); 
    and AND1 ( sa, a, not_select ); 
    and AND2 ( sb, b,     select ); 
    or  OR1  ( z, sa, sb ); 
endmodule // mux 

// ------------------------- 
//  Guia_0701 - Modulo de Teste 
// -------------------------
module Guia_0701; 
    // ------------------------- definir dados 
    reg  x = 0, y = 0; // inputs
    reg  s = 0;        // input selecionavel
    wire z;            // output MUX
    wire a, b;         // output AND/NAND
    reg [2:0]i;

    // instancias
    f0701 MOD ( a, b, x, y );
    mux   MUX ( z, a, b, s );

    // valores iniciais 
    initial begin: start 
        x=1'b0; y=1'b0; s=1'b0;
    end // start
    
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0701 - Teste"); 
        $display("LU's module:");
        $display( "   x    y    s   AND NAND  MUX" );
        $monitor("%4b %4b %4b %4b %4b %4b", x, y, s, a, b, z ); 
        for ( i = 1; i < 4; i++ )
        begin
            #10 x=i[1]; y=i[0]; s = ~s;
        end // for
    end // main 
endmodule // Guia_0701 