/*
    Arquitetura de Computadores I - Guia_0104b.v
    812839 - Vinícius Miranda de Araújo
*/

module Guia_0104;

    integer base = 0; // decimal

    reg [7:0] a = 6'b010111, b = 6'b011110, c = 6'b100101, d = 6'b101011, e = 6'b101100; // binary

    initial begin : main
    $display ( "Guia_0104b\n" );

    $display ( "a = %6b" , a );
    base = a;
    $display ( "a = [%2b] [%2b] [%2b] = %d%d%d (4)\n", a[5:4], a[3:2], a[1:0], a[5:4], a[3:2], a[1:0] );

    $display ( "b = %6b" , b );
    base = b;
    $display ( "b = [%3b] [%3b] = %d%d (8)\n", b[5:3], b[2:0], b[5:3], b[2:0] );

    $display ( "c = %6b" , c );
    base = c;
    $display ( "c = [%4b] [%4b] = %d%d (16)\n", c[7:4], c[3:0], c[7:4], c[3:0] );

    $display ( "d = %6b" , d );
    base = d;
    $display ( "d = [%3b] [%3b] = %d%d (8)\n", d[5:3], d[2:0], d[5:3], d[2:0] );

    $display ( "e = %6b" , e );
    base = e;
    $display ( "e = [%2b] [%2b] [%2b] = %d%d%d (4)\n", e[5:4], e[3:2], e[1:0], e[5:4], e[3:2], e[1:0] );
    
    end // main

endmodule // Guia_0104
