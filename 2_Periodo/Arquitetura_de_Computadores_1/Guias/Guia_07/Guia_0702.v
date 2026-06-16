// ------------------------- 
// Guia_0702 - GATES 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  f0702 - GATES 
// ------------------------- 
module f0702( output a, output b, input x, input y );
    or  OR1  ( a, x, y ); // saida do OR
    nor NOR1 ( b, x, y ); // saida do NOR
endmodule // f0702

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
//  Guia_0702 - Modulo de Teste 
// -------------------------
module Guia_0702; 
    // ------------------------- definir dados 
    reg  x = 0, y = 0; // inputs
    reg  s = 0;        // input selecionavel
    wire z;            // output MUX
    wire a, b;         // output OR/NOR
    integer i = 0;

    // instancias
    f0702 MOD ( a, b, x, y );
    mux   MUX ( z, a, b, s );

    // valores iniciais 
    initial begin: start 
        x=1'b0; y=1'b0; s=1'b0;
    end // start
    
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0702 - Teste"); 
        $display("LU's module:");
        $display( "   x    y    s   OR   NOR  MUX" );
        $monitor("%4b %4b %4b %4b %4b %4b", x, y, s, a, b, z ); 
        for (i = 0; i < 4; i = i + 1) begin
            { x, y } = i;
            s = ~s; // alternar o valor de s
            #1;
        end // for
    end // main 
endmodule // Guia_0702 