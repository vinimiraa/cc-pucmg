/*
    Arquitetura de Computadores I - Guia_0305b.v
    812839 - Vinícius Miranda de Araújo
*/
module Guia_0305; 
    // define data  
    reg [5:0] a = 0 ; // binary 
    reg [7:0] b = 0 ; // binary 
    reg [7:0] bf = 0 ; // binary 
    reg [7:0] c = 0 ; // binary 
    reg [7:0] d = 0 ; // binary 
    reg [7:0] e = 0 ; // binary 

    reg [7:0] x = 0 ;
    reg [7:0] xf = 0 ;
    reg [7:0] y = 0 ;
    reg [7:0] yf = 0 ;
    integer z;
    // actions 
    initial  begin : main 
        $display ( "Guia_0305 - Tests" ); 

        x = 8'b110011;
        y = 8'b1101;
        a = x-y;
        $display( "a = %8b(2) - %8b(2) = %8b(2)\n", x, y, a );

        x = 8'b110;
        xf = 8'b11010000;
        y = 8'o3;
        yf = 8'o3;
        b = x - y;
        bf = xf - yf;
        $display( "b = %3b,%4b(2) - %o,%o(8) = %8b,%5b(2)\n", x[2:0], xf[7:4], y, yf, b , bf[4:0] );

        x = 8'b101101;
        y = 16'he;
        c = x - y;
        $display( "c = %d%d%d(4) - %h(2) = %5b(2)\n", x[5:4], x[3:2], x[1:0], y, c );

        x = 16'hd4;
        y = 8'b1011101;
        d = x + ~(y+1);
        $display( "d = %h(16) - %8b(2) = %8b(2)\n" , x, y, d );

        x = 67;
        y = 16'h3b;
        e = x - y;
        $display( "e = %d - %x = %8b\n", x, y , e );

    end // main 

endmodule // Guia_0305