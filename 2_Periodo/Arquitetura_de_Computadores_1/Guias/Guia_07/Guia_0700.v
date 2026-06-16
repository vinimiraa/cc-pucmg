// ------------------------- 
// Guia_0700 - GATES 
// Nome: Vinicius Miranda de Araujo 
// Matricula: 812839
// ------------------------- 

// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7 ( output s, input  a, input  b ); 
    // descrever por portas 
endmodule // f7 

// ------------------------- 
//  multiplexer 
// ------------------------- 
module mux ( output s, input  a, input  b, input  select ); 
    // definir dados locais 
    wire not_select; 
    wire sa; 
    wire sb; 
    // descrever por portas 
    not NOT1 ( not_select, select ); 
    and AND1 ( sa, a, not_select ); 
    and AND2 ( sb, b, select ); 
    or  OR1  ( s, sa, sb ); 
endmodule // mux 

module test_f7; 
    // ------------------------- definir dados 
    reg  x; 
    reg  y; 
    reg  s; 
    wire w; 
    wire z; 
    f7 modulo ( w, x, y ); 
    mux MUX1 ( z, x, y, s ); 
    // ------------------------- parte principal 
    initial begin : main 
        $display("Guia_0700 - Vinicius MIranda de Araujo - 812839"); 
        $display("Test LU's module"); 
        $display("   x    y    s    z"); 
        x = 1'b0;  y = 1'b1;  s = 1'b0; 
        // projetar testes do modulo 
        #1  $monitor("%4b %4b %4b %4b", x, y, s, z); 
        #1  s = 1'b1; 
    end // main 

endmodule // test_f7 