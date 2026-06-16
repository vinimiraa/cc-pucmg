// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839 
// --------------------- 

// --------------------- 
// fxyz
// --------------------- 

module fxyzA(output s, 
            input  x, y, z); 
    assign s = x & (~y | ~z);  
endmodule // fxyzA

module fxyzB(output s, 
            input  x, y, z); 
    assign s = ~( x | ~y ) & z ;  
endmodule // fxyzB

module fxyzC(output s, 
            input  x, y, z); 
    assign s = ~( ~x & y ) & ~z ;  
endmodule // fxyzC 

module fxyzD(output s, 
            input  x, y, z); 
    assign s = ~( ~x & ~y ) & ~z; 
endmodule // fxyzD

module fxyzE(output s, 
            input  x, y, z); 
    assign s = ( x | y ) & ~( ~y & z ); 
endmodule // fxyzE

module Guia_0401; 
    reg   x, y, z; 
    wire  s1, s2, s3, s4, s5; 
    // instancias 
    fxyzA FXYZA (s1, x, y, z); 
    fxyzB FXYZB (s2, x, y, z); 
    fxyzC FXYZC (s3, x, y, z); 
    fxyzD FXYZD (s4, x, y, z); 
    fxyzE FXYZE (s5, x, y, z); 

    // valores iniciais 
    initial begin: start 
        x=1'bx; y=1'bx; z=1'bx;   // indefinidos 
    end 

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0401 - Test"); 

        // monitoramento
        $display("\na.)"); 
        $display(" x  y  z  = s1"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s1); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;

        $display("\nb.)"); 
        $display(" x  y  z  = s2"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s2); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;

        $display("\nc.)"); 
        $display(" x  y  z  = s3"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s3); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;

        $display("\nd.)"); 
        $display(" x  y  z  = s4"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s4); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;

        $display("\ne.)"); 
        $display(" x  y  z  = s5"); 
        $monitor("%2b %2b %2b  = %2b", x, y, z, s5); 
        // sinalizacao 
        #1  x=0; y=0; z=0;
        #1  x=0; y=0; z=1;
        #1  x=0; y=1; z=0;
        #1  x=0; y=1; z=1;
        #1  x=1; y=0; z=1;
        #1  x=1; y=0; z=0;
        #1  x=1; y=1; z=1;
        #1  x=1; y=1; z=0;
    end // end main

endmodule // Guia_0401 