// ---------------------
// TRUTH TABLE 
// Nome: Vinicius Miranda de Araujo
// Matricula: 812839 
// --------------------- 

// --------------------- 
// PoS
// --------------------- 

module PoS (output S1,
            output S2,
            output S3,
            output S4,
            output S5,
            input  X, Y, W, Z); // MAXTERMOS
    assign S1 = ( X |  Y | ~Z) 
              & (~X |  Y | ~Z) 
              & (~X | ~Y |  Z) 
              & (~X | ~Y | ~Z)
              ;
    assign S2 = ( X |  Y |  Z) 
              & (~X |  Y |  Z) 
              & (~X |  Y | ~Z) 
              & (~X | ~Y | ~Z)
              ;
    assign S3 = ( X |  Y |  W |  Z) 
              & ( X |  Y |  W | ~Z) 
              & ( X |  Y | ~W |  Z) 
              & ( X | ~Y |  W | ~Z)
              & ( X | ~Y | ~W |  Z)
              & (~X |  Y |  W |  Z)
              & (~X |  Y | ~W | ~Z)
              & (~X | ~Y |  W | ~Z)
              ;
    assign S4 = ( X |  Y |  W | ~Z) 
              & ( X |  Y | ~W |  Z) 
              & ( X | ~Y |  W |  Z) 
              & ( X | ~Y | ~W |  Z)
              & (~X |  Y |  W |  Z)
              & (~X |  Y |  W | ~Z)
              & (~X | ~Y | ~W |  Z)
              ;
    assign S5 = ( X |  Y |  W |  Z) 
              & ( X |  Y |  W | ~Z) 
              & ( X |  Y | ~W |  Z) 
              & ( X |  Y | ~W | ~Z)
              & ( X | ~Y |  W | ~Z)
              & (~X |  Y | ~W |  Z)
              & (~X |  Y | ~W | ~Z)
              ;
endmodule // PoS

// --------------------- 
// Guia_0404
// --------------------- 

module Guia_0404; 
    reg   X = 0, Y = 0, W = 0, Z = 0; 
    wire  S1, S2, S3, S4, S5;
    integer  i = 0; 
    // instancias 
    PoS POS (S1, S2, S3, S4, S5 , X, Y, W, Z); 

    // valores iniciais 
    initial begin: start 
        X=1'bx; Y=1'bx; W=1'bx; Z=1'bx;  // indefinidos 
    end 

    // parte principal 
    initial begin: main 
        // identificacao 
        $display("Guia_0404 - Test"); 

        // monitoramento 
        $display("\na.)"); 
        $display(" X  Y  Z  = S1"); 
        $monitor("%2b %2b %2b  = %2b", X, Y, Z, S1); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // end for

        $display("\nb.)");
        $display(" X  Y  Z  = S2"); 
        $monitor("%2b %2b %2b  = %2b", X, Y, Z, S2); 
        for (i = 0; i < 8; i = i + 1) begin
            { X, Y, Z } = i;
            #1;
        end // end for

        $display("\nc.)");
        $display(" X  Y  W  Z  = S3"); 
        $monitor("%2b %2b %2b %2b  = %2b", X, Y, W, Z, S3); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // end for

        $display("\nd.)"); 
        $display(" X  Y  W  Z  = S4"); 
        $monitor("%2b %2b %2b %2b  = %2b", X, Y, W, Z, S4); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // end for

        $display("\ne.)"); 
        $display(" X  Y  W  Z  = S5"); 
        $monitor("%2b %2b %2b %2b  = %2b", X, Y, W, Z, S5); 
        for (i = 0; i < 16; i = i + 1) begin
            { X, Y, W, Z } = i;
            #1;
        end // end for
    end // end main 

endmodule // Guia_0404