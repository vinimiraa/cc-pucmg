// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839
// --------------------- 

// --------------------- 
// Expressoes
// --------------------- 

module g0608 ( output s1,
               output s2,
               input  w, x, y, z ); // mintermos
    assign s1 = (w & x & y & z) | (w & x & ~y & ~z) | (w & ~x & ~y & z) | (~w & ~x & y & ~z); // expressao 
    assign s2 = (w & x & y & z) | (w & x & ~y & ~z) | (w & ~x & ~y & z) | (~w & ~x & y & ~z); // expressao simplificada
endmodule // g0608

module f0608 ( output s, input w, input x, input y, input z ); 
    // definir dado local   
    wire not_x, not_y;
    wire a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12;
    wire o1, o2;
    // descrever por portas
    not NOT1 ( not_w, w );
    not NOT2 ( not_x, x );
    not NOT3 ( not_y, y );
    not NOT4 ( not_z, z ); 
    and AND1 ( a1, w, x );
    and AND2 ( a2, y, z );
    and AND3 ( a3, a1, a2 ); // (w & x & y & z)
    and AND4 ( a4, w, x );
    and AND5 ( a5, not_y, not_z );
    and AND6 ( a6, a4, a5 ); // (w & x & ~y & ~z)
    and AND7 ( a7, w, not_x );
    and AND8 ( a8, not_y, z );
    and AND9 ( a9, a7, a8 ); // (w & ~x & ~y & z)
    and AND10( a10, not_w, not_x );
    and AND11( a11, y, not_z );
    and AND12( a12,a10,a11); // (~w & ~x & y & ~z)
    or  OR1  ( o1, a3, a6 );
    or  OR2  ( o2, a9, a12);
    or  OR3  ( s , o1, o2 );
endmodule // f0608

module fwxyz (output s1, input w, input  x, input y, input z); 
    assign s1 = (w & x & y & z) | (w & x & ~y & ~z) | (w & ~x & ~y & z) | (~w & ~x & y & ~z); 
endmodule // fwxyz 

// --------------------- 
// Guia_0608 
// --------------------- 

module Guia_0608; 
    reg   w = 0, x = 0, y = 0, z = 0; 
    wire  s1, s2, s3; 
    integer i = 0; 
    // instancias 
    g0608 EXP(s1, s2, w, x, y, z);
    f0608 CIR(s3, w, x, y, z);
    // fwxyz EXP(s1, w, x, y, z);
    // valores iniciais 
    initial begin: start 
        w=1'bx; x=1'b0; y=1'b0; z=1'b0;   // indefinidos 
    end // start

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0608 - Teste ");  
        
        // monitoramento 
        $display("\nExpressao:");
        $display(" w  x  y  z = s1"); 
        $monitor("%2b %2b %2b %2b = %2b", w, x, y, z, s1 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { w, x, y, z } = i;
            #1;
        end // for

        $display("\nExpressao \"simplificada\":");
        $display(" w  x  y  z = s2"); 
        $monitor("%2b %2b %2b %2b = %2b", w, x, y, z, s2 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { w, x, y, z } = i;
            #1;
        end // for

        $display("\nExpressao \"simplificada\" feita com Circuito:");
        $display(" w  x  y  z = s3"); 
        $monitor("%2b %2b %2b %2b = %2b", w, x, y, z, s3 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { w, x, y, z } = i;
            #1;
        end // for
        
    end // main

endmodule // Guia_0608 