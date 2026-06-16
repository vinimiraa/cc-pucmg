// constant definitions 
`define found    1 
`define notfound 0 

// ----------------
// --- FSM_1010
// ----------------
module FSM_1010 (
    output reg y, // Saída indicando se a sequência foi encontrada
    input x,      // Entrada de dados
    input clk,    // Clock
    input reset   // Sinal de reset
);

    // Definição dos estados
    parameter [1:0]
        start = 2'b00,
        id1    = 2'b01,
        id10   = 2'b10,
        id101  = 2'b11;

    // Variáveis de estado
    reg [1:0] E1;
    reg [1:0] E2;

    // Lógica para a saída y e para o próximo estado
    always @( x or E1 ) begin
        y = `notfound;
        case ( E1 )
            start: begin
                if ( x ) begin
                    E2 = id1;
                end else begin
                    E2 = start;
                end
            end
            id1: begin
                if ( x ) begin
                    E2 = id10;
                end else begin
                    E2 = start;
                end
            end
            id10: begin
                if ( x ) begin
                    E2 = id101;
                end else begin
                    E2 = start;
                end
            end
            id101: begin
                if ( x ) begin
                    E2 = start;
                    y = `found; // Indica que a sequência foi encontrada
                end else begin
                    E2 = start;
                end
            end
            default: begin
                E2 = start; // Estado indefinido
            end
        endcase
    end

    // Lógica para o próximo estado
    always @( posedge clk or negedge reset ) begin
        if ( reset ) begin
            E1 = E2; // Reinicia o estado
        end else begin
            E1 = 0; // Atualiza o estado atual
        end
    end
endmodule // FSM_1010

// ----------------
// --- Teste
// ----------------
module Guia_1101; 
    reg   clk, reset, x; 
    wire  m1; 

    FSM_1010  fsm1 ( m1, x, clk, reset ); 

    initial begin
    $display ( "Time     X    FSM" ); 
        // initial values 
        clk   = 1; 
        reset = 0; 
        x     = 0; 

        // input signal changing 
        #5   reset = 1; 
        #10  x = 1; 
        #10  x = 0; 
        #10  x = 1; 
        #20  x = 0; 
        #10  x = 1; 
        #10  x = 1; 
        #10  x = 0; 
        #10  x = 1; 

        #30 $finish; 
    end // initial 

    always 
        #5 clk = ~clk; 

    always @( posedge clk ) begin 
        $display ( "%4d  %4b  %4b", $time, x, m1 ); 
    end // always at positive edge clocking changing 

endmodule // Guia_1101