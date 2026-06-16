// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839
// --------------------- 

// --------------------- 
// Expressoes
// --------------------- 

module g0607 ( output S1,
                  output S2,
                  input  X, Y, Z ); // MAXTERMOS
    assign S1 = ( X | ~Y | ~Z ) & (~X | Y |  Z) & ( X | ~Y | Z ); // expressao 
    assign S2 = (X|~Y) & (~X|Y|Z);                                // expressao simplificada
endmodule // g0607

module f0607 ( output S, input X, input Y, input Z ); 
    // definir dado local   
    wire not_x, not_y;
    wire o1, o2, o3;
    // descrever por portas
    not NOT1 ( not_x, X );
    not NOT2 ( not_y, Y );
    or  OR1  ( o1, X, not_y );
    or  OR2  ( o2, not_x, Y );
    or  OR3  ( o3 , o2, Z );
    and AND1 ( S, o1, o3 );
endmodule // f0607

module FXYZ (output S1, input  X, input Y, input Z); // MAXTERMOS
    assign S1 = ( X | ~Y | ~Z ) & (~X | Y |  Z) & ( X | ~Y | Z ); 
endmodule // FXYZ 

// --------------------- 
// Guia_0607 
// --------------------- 

module Guia_0607; 
    reg   X = 0, Y = 0, Z = 0; 
    wire  S1, S2, S3; 
    integer i = 0; 
    // instancias 
    g0607 EXP(S1, S2, X, Y , Z);
    f0607 CIR(S3, X, Y, Z);
    // valores iniciais 
    initial begin: start 
        X=1'b0; Y=1'b0; Z=1'b0;   // indefinidos 
    end // start

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0607 - Teste ");  
        
        // monitoramento 
        $display("\nExpressao:");
        $display(" X  Y  Z = S1"); 
        $monitor("%2b %2b %2b = %2b", X, Y, Z, S1 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // for

        $display("\nExpressao simplificada:");
        $display(" X  Y  Z = S2"); 
        $monitor("%2b %2b %2b = %2b", X, Y, Z, S2 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // for

        $display("\nExpressao simplificada feita com Circuito:");
        $display(" X  Y  Z = S3"); 
        $monitor("%2b %2b %2b = %2b", X, Y, Z, S3 ); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // for
    end // main

endmodule // Guia_0607 