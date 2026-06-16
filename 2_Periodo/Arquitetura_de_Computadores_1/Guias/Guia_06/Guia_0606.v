// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839
// --------------------- 

// --------------------- 
// Expressoes
// --------------------- 

module g0606 ( output S1,
               output S2,
               input  X, Y, W, Z ); // MAXTERMOS
    assign S1 = ( ( ~(~X|~Y|W) & ~(X&Y&~W) ) | ~( (Y&Z&W) | ~X ) ); // expressao 
    assign S2 = (X|W) & (X|~W) & (~Y|~W|~Z);                        // expressao simplificada
endmodule // g0606

module f0606 ( output S, input X, input Y, input W, input Z ); 
    // definir dado local   
    wire not_y, not_w, not_z;
    wire o1, o2, o3, o4;
    wire a1;
    // descrever por portas
    not NOT1 ( not_y, Y );
    not NOT2 ( not_w, W );
    not NOT3 ( not_z, Z );
    or  OR1  ( o1, X, W );
    or  OR2  ( o2, X, not_w );
    or  OR3  ( o3, not_y, not_w );
    or  OR4  ( o4, o3, not_z );
    and AND1 ( a1, o1, o2 );
    and AND2 ( S, a1, o4 );
endmodule // f0606

// --------------------- 
// Guia_0606 
// --------------------- 

module Guia_0606; 
    reg   X = 0, Y = 0, W = 0, Z = 0; 
    wire  S1, S2, S3; 
    integer i = 0; 
    // instancias 
    g0606 EXP (S1, S2, X, Y, W, Z); 
    f0606 CIR (S3, X, Y, W, Z);
    // valores iniciais 
    initial begin: start 
        X=1'bx; Y=1'bx; W=1'bz; Z=1'bx;   // indefinidos 
    end // start

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0606 - Teste ");  
        
        // monitoramento 
        $display("\nExpressao:");
        $display(" X  Y  W  Z = S1"); 
        $monitor("%2b %2b %2b %2b = %2b", X, Y, W, Z, S1 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // for

        $display("\nExpressao simplificada:");
        $display(" X  Y  W  Z = S2"); 
        $monitor("%2b %2b %2b %2b = %2b", X, Y, W, Z, S2 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // for

        $display("\nExpressao simplificada feita com Circuito:");
        $display(" X  Y  W  Z = S3"); 
        $monitor("%2b %2b %2b %2b = %2b", X, Y, W, Z, S3 ); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // for

    end // main

endmodule // Guia_0606 