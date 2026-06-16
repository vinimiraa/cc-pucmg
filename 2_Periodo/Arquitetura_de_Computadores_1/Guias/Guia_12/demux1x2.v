// ------------------------- 
// --- Demultiplexador 1x2
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// ------------------------- 
module demux1x2 ( output o1, output o2, input i1, input select ); 
    // definir dados locais 
    wire not_select; 
    // descrever por portas 
    not NOT1 ( not_select, select ); 
    and AND1 ( o1, i1, not_select ); 
    and AND2 ( o2, i1, select ); 
endmodule // demux1x2