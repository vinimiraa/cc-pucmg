/*
    Arquitetura de Computadores I - Guia_0301b.v
    812839 - Vinícius Miranda de Araújo
*/

module Guia_0301; 
    // define data 
    reg [5:0] a = 8'b001_100   ; // binary 
    reg [7:0] b = 8'b0000_1110 ; // binary 
    reg [5:0] c = 8'b100_101   ; // binary 
    reg [6:0] d = 8'b010_0101  ; // binary 
    reg [7:0] e = 8'b0011_0101 ; // binary 
    reg [5:0] z = 0  ; // binary 
    reg [6:0] x = 0  ; // binary 
    reg [7:0] y = 0  ; // binary 
    // actions 
    initial begin : main 
        $display ( "Guia_0301 - Tests\n" ); 

        $display ( "a = %6b -> C1(a) = %6b", a, ~a );

        $display ( "b = %8b -> C1(b) = %8b", b, ~b ); 

        z = ~c+1; 
        $display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b", c, ~c, z ); 

        x = ~d+1; 
        $display ( "d = %6b -> C1(d) = %6b -> C2(d) = %6b", d, ~d, x ); 

        y = ~e+1; 
        $display ( "e = %8b -> C1(e) = %8b -> C2(e) = %8b", e, ~e, y ); 
    end // main 

endmodule // Guia_0301