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
    assign s1 = (~x &  y & ~z) 
              | ( x & ~y &  z) 
              | ( x &  y & ~z) 
              | ( x &  y &  z)
              ;
    assign s2 = (~x & ~y &  z) 
              | (~x &  y &  z) 
              | ( x &  y & ~z) 
              | ( x &  y &  z)
              ;
    assign s3 = (~x & ~y & ~w &  z) 
              | (~x & ~y &  w & ~z) 
              | (~x &  y & ~w & ~z) 
              | (~x &  y &  w & ~z) 
              | (~x &  y &  w &  z) 
              | ( x &  y & ~w & ~z) 
              | ( x &  y &  w &  z) 
              ;
    assign s4 = (~x & ~y & ~w &  z) 
              | (~x & ~y &  w & ~z)
              | (~x &  y & ~w &  z)
              | ( x & ~y & ~w & ~z)
              | ( x & ~y &  w & ~z) 
              | ( x &  y & ~w & ~z) 
              | ( x &  y & ~w &  z) 
              ;
    assign s5 = (~x & ~y & ~w & ~z)
              | (~x & ~y &  w & ~z)
              | (~x &  y & ~w &  z)
              | (~x &  y &  w &  z)
              | ( x & ~y & ~w &  z)
              | ( x &  y & ~w &  z)
              ;
endmodule // SoP

// --------------------- 
// Guia_0403 
// --------------------- 

module Guia_0403; 
    reg   x = 0, y = 0, w = 0, z = 0; 
    wire  s1, s2, s3, s4, s5;
    integer  i = 0; 
    // instancias 
    SoP SOP (s1, s2, s3, s4, s5 , x, y, w, z); 

    // valores iniciais 
    initial begin: start 
        x=1'bx; y=1'bx; w=1'bx; z=1'bx;  // indefinidos 
    end 

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0403 - Test"); 

        // monitoramento 
        $display("\na.)"); 
        $display(" x  y  z  = s1");
        $monitor("%2b %2b %2b  = %2b", x, y, z, s1); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // end for

        $display("\nb.)");
        $display(" x  y  z  = s2"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s2); 
        for (i = 0; i < 8; i = i + 1) begin
            { x, y, z } = i;
            #1;
        end // end for

        $display("\nc.)"); 
        $display(" x  y  w  z  = s3");
        $monitor("%2b %2b %2b %2b  = %2b", x, y, w, z, s3); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // end for

        $display("\nd.)"); 
        $display(" x  y  w  z  = s4");
        $monitor("%2b %2b %2b %2b  = %2b", x, y, w, z, s4); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // end for

        $display("\ne.)");
        $display(" x  y  w  z  = s5"); 
        $monitor("%2b %2b %2b %2b  = %2b", x, y, w, z, s5); 
        for (i = 0; i < 16; i = i + 1) begin
            { x, y, w, z } = i;
            #1;
        end // end for
    end // end main 

endmodule // Guia_0403 