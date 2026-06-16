// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839
// --------------------- 

// --------------------- 
// SoP 
// --------------------- 

module SoP (output s1,
            output s2,
            output s3,
            output s4,
            output s5,
            input  x, y, w, z); // mintermos 
    assign s1 = (~x & y) 
              | ( x & y )
              ; 
    assign s2 = (~x & ~y) 
              | (~x & y) 
              | (x & y)
              ; 
    assign s3 = (~x&~y&~z) 
              | (~x&~y&z) 
              | (~x&y&z) 
              | (x&~y&~z) 
              | (x&y&~z) 
              | (x&y&z)
              ;
    assign s4 = (~x&~y&~z) 
              | (~x&y&~z) 
              | ( x&~y&~z) 
              | (x&~y&z) 
              | (x&y&~z)
              ;
    assign s5 = (~x&~y&~w&~z) 
              | (~x&~y&~w&z) 
              | (~x&~y&w&z) 
              | (~x&y&~w&~z) 
              | (~x&y&~w&z) 
              | (x&~y&~w&~z) 
              | (x&~y&~w&z) 
              | (x&~y&w&~z) 
              | (x&y&w&~z) 
              | (x&y&w&z)
              ;
endmodule // SoP

// --------------------- 
// PoS 
// --------------------- 

module PoS (output S1,
            output S2,
            output S3,
            output S4,
            output S5,
            input  X, Y, W, Z); 
            // MAXTERMOS 
    assign S1 = (X|Y) 
              & (~X|Y)
              ; 
    assign S2 = (~X|Y)
              ; 
    assign S3 = (X|~Y|Z)
              & (~X|Y|~Z)
              ;
    assign S4 = (X|Y|~Z) 
              & (X|~Y|~Z) 
              & (~X|~Y|~Z)
              ;
    assign S5 = (X|Y|~W|Z) 
              & (X|~Y|~W|Z) 
              & (X|~Y|~W|~Z) 
              & (~X|Y|~W|~Z) 
              & (~X|~Y|W|Z) 
              & (~X|~Y|W|~Z)
              ;
endmodule // PoS 

// --------------------- 
// Guia_0405 
// --------------------- 

module Guia_0405; 
    reg   x = 0, y = 0, w = 0, z = 0; 
    wire  s1, s2, s3, s4, s5; 
    wire  S1, S2, S3, S4, S5;
    integer i = 0; 
    // instancias 
    SoP SOP (s1, s2, s3, s4, s5, x, y, w, z); 
    PoS POS (S1, S2, S3, S4, S5, x, y, w, z); 

    // valores iniciais 
    initial begin: start 
        x=1'bx; y=1'bx; w=1'bx; z=1'bx;   // indefinidos 
    end 

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0405 - Teste ");  
        
        // monitoramento 
        $display("\na.)");
        $display(" x  y = s1 S1"); 
        $monitor("%2b %2b = %2b %2b", x, y, s1, S1); 
        for (i = 0; i < 4; i = i + 1) begin
            { x, y } = i;
            #1;
        end // end for

        $display("\nb.)");
        $display(" x  y = s2 S2"); 
        $monitor("%2b %2b = %2b %2b", x, y, s2, S2); 
        for (i = 0; i < 4; i = i + 1) begin
            { x, y } = i;
            #1;
        end // end for

        $display("\nc.)");
        $display(" x  y  z = s3 S3"); 
        $monitor("%2b %2b %2b = %2b %2b", x, y, z, s3, S3); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // end for

        $display("\nd.)");
        $display(" x  y  z = s4 S4"); 
        $monitor("%2b %2b %2b = %2b %2b", x, y, z, s4, S4); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // end for

        $display("\ne.)");
        $display(" x  y  w  z = s5 S5"); 
        $monitor("%2b %2b %2b %2b = %2b %2b", x, y, w, z, s5, S5); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // end for
    end 

endmodule // Guia_0405 