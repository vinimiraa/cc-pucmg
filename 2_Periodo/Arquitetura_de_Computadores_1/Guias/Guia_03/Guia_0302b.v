/*
    Arquitetura de Computadores I - Guia_0302b.v
    812839 - Vinícius Miranda de Araújo
*/
module Guia_0302; 
    // define data 
    reg [5:0] a = 8'o132 ; // b-4 
    reg [7:0] b = 8'h4b  ; // hex 
    reg [5:0] c = 8'o213 ; // b-4 
    reg [9:0] d = 8'o154 ; // octal 
    reg [7:0] e = 8'hb8  ; // hex 
    reg [5:0] c1  = 0    ; // binary 
    reg [9:0] d1  = 0    ; // binary 
    reg [7:0] e1  = 0    ; // binary 
    // actions 
    initial begin : main 
        $display ( "Guia_0302 - Tests" );

        $display ( "a = %6b -> C1(a) = %6b", a, ~a ); 

        $display ( "b = %8b -> C1(b) = %8b", b, ~b ); 

        c1 = ~c+1; 
        $display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b", c, ~c, c1 );
        
        d1 = ~d+1; 
        $display ( "d = %10b -> C1(d) = %10b -> C2(d) = %10b", d, ~d, d1 );
        
        e1 = ~e+1; 
        $display ( "e = %8b -> C1(e) = %8b -> C2(e) = %8b", e, ~e, e1 ); 
        
    end // main 

endmodule // Guia_0302