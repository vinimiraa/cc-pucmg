/*
    Arquitetura de Computadores I - Guia_0205b.v
    812839 - Vinícius Miranda de Araújo
*/

module Guia_0205; 
    
    reg [7:0] a  ; // binary 
    reg [7:0] af ; // fractional binary
    reg [7:0] b  ; // binary 
    reg [7:0] bf ; // fractional binary
    reg [7:0] i;
    reg [7:0] f;
    
    initial begin : main 

        $display("Guia_0205 - Tests\n"); 

        a  = 8'b000_0101 ;  // binary 
        af = 8'b0100_0000 ; // fractional binary
        b  = 8'b000_0011;   // binary 
        bf = 8'b0110_0000;  // fractional binary
        $display("a = %8b", a);
        $display("b = %8b", b); 
        $display("af = %8b", af);
        $display("bf = %8b", bf); 
        i = a + b; 
        f = af + bf; 
        $display("a.) = a+b = %b,%b\n", i, f);

        a  = 8'b0000_1001 ;
        b  = 8'b0000_0010 ;
        af = 8'b1010_0000 ;
        bf = 8'b1100_0000 ;
        $display("a = %8b", a);
        $display("b = %8b", b); 
        $display("af = %8b", af);
        $display("bf = %8b", bf); 
        i = a - b;
        f = af - bf;
        $display("b.) = a-b = %b,%b\n", i, f);

        a  = 8'b0000_0100 ;
        b  = 8'b0000_0011 ;
        af = 8'b0000_0101 ;
        bf = 8'b0000_0101 ;
        $display("a = %8b", a);
        $display("b = %8b", b); 
        $display("af = %8b", af);
        $display("bf = %8b", bf); 
        i = a * b;
        f = af * bf;  
        $display("c.) = a*b = %b,%b\n", i, f);

        a  = 8'b0001_0111 ;
        b  = 8'b0000_0010 ;
        af = 8'b0100_0000 ;
        bf = 8'b0110_0000 ;
        $display("a = %8b", a);
        $display("b = %8b", b); 
        $display("af = %8b", af);
        $display("bf = %8b", bf); 
        i = a / b;
        f = af / bf; 
        $display("d.) = a/b = %b,%b\n", i, f);

        a  = 8'b0110_1011 ;
        b  = 8'b0000_1011 ;
        $display("a = %8b", a);
        $display("b = %8b", b); 
        i = a % b;
        $display("e.) = a%%b = %b\n", i);

    end // main 

endmodule // Guia_0205
