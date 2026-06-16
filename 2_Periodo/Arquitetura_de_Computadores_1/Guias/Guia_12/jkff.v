// -----------------------
// --- Flip-Flop tipo JK
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// -----------------------
module jkff ( output q, output qnot, input  j, input k,  input clk, input preset, input clear ); 
    reg q, qnot;

    always @( posedge clk or posedge preset or posedge clear ) 
    begin 
        if ( clear   ) 
            begin q <= 0; qnot <= 1; end 
        else if ( preset  ) 
            begin q <= 1; qnot <= 0; end 
        else if (  j & ~k ) 
            begin q <= 1; qnot <= 0; end 
        else if ( ~j &  k ) 
            begin q <= 0; qnot <= 1; end 
        else if (  j &  k ) 
            begin q <= ~q; qnot <= ~qnot; end 
    end  
endmodule // jkff