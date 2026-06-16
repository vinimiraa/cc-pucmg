/*
    Arquitetura de Computadores I - Guia_0101b.v
    812839 - Vinícius Miranda de Araújo
*/

module Guia_0101;

    integer a = 23, b = 57, c = 732, d = 321, e = 364;

    reg [9:0] bin = 0; // binary (bits - little endian)
    
    initial begin : main
    $display ( "Guia_0101b\n" );

    $display ( "a = %d" , a );
    bin = a;
    $display ( "bin = %8b\n", bin );

    $display ( "b = %d" , b );
    bin = b;
    $display ( "bin = %8b\n", bin );

    $display ( "c = %d" , c );
    bin = c;
    $display ( "bin = %8b\n", bin );

    $display ( "d = %d" , d );
    bin = d;
    $display ( "bin = %8b\n", bin );

    $display ( "e = %d" , e );
    bin = e;
    $display ( "bin = %8b\n", bin );
    
    end // main

endmodule // Guia_0101
