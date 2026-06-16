/*
    Arquitetura de Computadores I - Guia_0103b.v
    812839 - Vinícius Miranda de Araújo
*/

module Guia_0103;
    
    integer a = 67, b = 58, c = 76, d = 157, e = 735; // decimal

    reg [9:0] base = 0; // binary

    initial begin : main
    $display ( "Guia_0103b\n" );

    $display ( "a = %d" , a );
    base = a;
    $display ( "a = %B (2) = %o (8) = %x (16) = %X (16)\n", base, base, base, base );

    $display ( "b = %d" , b );
    base = b;
    $display ( "b = %B (2) = %o (8) = %x (16) = %X (16)\n", base, base, base, base );

    $display ( "c = %d" , c );
    base = c;
    $display ( "c = %B (2) = %o (8) = %x (16) = %X (16)\n", base, base, base, base );

    $display ( "d = %d" , d );
    base = d;
    $display ( "d = %B (2) = %o (8) = %x (16) = %X (16)\n", base, base, base, base );

    $display ( "e = %d" , e );
    base = e;
    $display ( "e = %B (2) = %o (8) = %x (16) = %X (16)\n", base, base, base, base );

    end // main
    
endmodule // Guia_0103
