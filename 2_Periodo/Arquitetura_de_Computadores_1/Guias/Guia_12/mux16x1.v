// ------------------------- 
// --- Multiplexador 16x1
// Autor: Vinícius Miranda de Araújo Matrícula: 812839
// ------------------------- 
module mux16x1 (
    output o1, o2, o3, o4, o5, o6, o7, o8,
    input i1_1, i2_1, i3_1, i4_1, i5_1, i6_1, i7_1, i8_1,
    input i1_2, i2_2, i3_2, i4_2, i5_2, i6_2, i7_2, i8_2,
    input select1 );

    // Definição de sinais locais
    wire not_select1;
    wire s1_1, s2_1, s3_1, s4_1, s5_1, s6_1, s7_1, s8_1;
    wire s1_2, s2_2, s3_2, s4_2, s5_2, s6_2, s7_2, s8_2;
    // Descrição das portas lógicas
    not NOT1 ( not_select1, select1 );
    and AND_1  ( s1_1, i1_1, not_select1 );
    and AND_2  ( s2_1, i2_1, not_select1 );
    and AND_3  ( s3_1, i3_1, not_select1 );
    and AND_4  ( s4_1, i4_1, not_select1 );
    and AND_5  ( s5_1, i5_1, not_select1 );
    and AND_6  ( s6_1, i6_1, not_select1 );
    and AND_7  ( s7_1, i7_1, not_select1 );
    and AND_8  ( s8_1, i8_1, not_select1 );
    and AND_9  ( s1_2, i1_2, select1     );
    and AND_10 ( s2_2, i2_2, select1     );
    and AND_11 ( s3_2, i3_2, select1     );
    and AND_12 ( s4_2, i4_2, select1     );
    and AND_13 ( s5_2, i5_2, select1     );
    and AND_14 ( s6_2, i6_2, select1     );
    and AND_15 ( s7_2, i7_2, select1     );
    and AND_16 ( s8_2, i8_2, select1     );
    or  OR_1   ( o1, s1_1, s1_2 );
    or  OR_2   ( o2, s2_1, s2_2 );
    or  OR_3   ( o3, s3_1, s3_2 );
    or  OR_4   ( o4, s4_1, s4_2 );
    or  OR_5   ( o5, s5_1, s5_2 );
    or  OR_6   ( o6, s6_1, s6_2 );
    or  OR_7   ( o7, s7_1, s7_2 );
    or  OR_8   ( o8, s8_1, s8_2 );
endmodule // mux16x1
