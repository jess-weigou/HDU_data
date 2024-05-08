`timescale 1ns / 1ps
module Board(sw, swb, led, clk, which, seg, enable);
    input [1:32] sw;
    output [1:32] led;
    input clk; 
    input [1:6] swb;
    output [2:0] which;
    output [7:0] seg;
    output reg enable = 1; 

//    barrelshifter
//    reg [31:0] Shift_Data;
//    reg [7:0] Shift_Num;
//    reg Carry_flag;
//    reg [2:0] SHIFT_OP;
//    wire [31:0] datatube; 
//    barrelshifter32 BB1(
//        .Shift_Data(Shift_Data),
//        .Shift_Num(Shift_Num),
//        .Carry_flag(Carry_flag),
//        .SHIFT_OP(SHIFT_OP),
//        .Shift_out(datatube),
//        .Shift_carry_out(led[1])
//    );
//    always@(posedge clk)begin
//        if(swb[1] == 1'b1)begin
//            Shift_Data[31:0] <= sw[1:32];
//        end
//        if(swb[2] == 1'b1)begin
//            SHIFT_OP[2:0] <= sw[1:3];
//            Shift_Num [7:0]<= sw[9:16];
//        end
//        if(swb[4] == 1'b1)begin
//            SHIFT_OP <= 0;
//            Shift_Num <= 0;
//            Shift_Data <= 0; 
//         end 
//    end
//    always@(swb[3])begin
//            Carry_flag <= swb[3];
//    end
//    Display Display_Instance(.clk(clk), .data(datatube),
//        .which(which), .seg(seg));

//    ALU    
    // wire [3:0] ALU_NZCV;
    // reg [3:0] NZCV;
    // wire [31:0] F;
    // wire N,Z,C,V,S;
    // wire Shift_carry_out;
    // reg [31:0] A;
    // reg [31:0] Shift_Data;
    // reg [7:0] Shift_Num;
    // reg Carry_flag;
    // reg [2:0] SHIFT_OP;
    // reg [3:0] ALU_OP;
    // wire [31:0] Shift_out; 
    // reg [31:0] datatube;
    // assign S = swb[4];
    // assign  led[1:4] = NZCV[3:0];
    
    // always@(S or swb[5])begin
    //     if(S == 0)begin
    //        NZCV <= ALU_NZCV; 
    //     end
    //     if(swb[5] == 1)begin
    //        NZCV <= {sw[8],sw[16],sw[24],sw[32]};
    //     end
    // end
    
    // always@(*)begin
    //     if(swb[1] == 1'b1 && swb[6] == 1'b0)begin
    //         datatube[31:0] <= A[31:0];
    //     end
    //     else if(swb[2] == 1'b1 && swb[6] == 1'b0)begin
    //         datatube[31:0] <= Shift_Data;
    //     end
    //     else if(swb[3] == 1'b1 && swb[6] == 1'b0)begin
    //         datatube[31:0] <= {ALU_OP,1'b0,SHIFT_OP,Shift_Num,3'b0,N,3'b0,Z,3'b0,C,3'b0,V};
    //     end
    //     else if(swb[1] == 1'b1 && swb[6] == 1'b1)begin
    //         A[31:0] <= sw[1:32]; 
    //     end
    //     else if(swb[2] == 1'b1 && swb[6] == 1'b1)begin
    //         Shift_Data <= sw[1:32];        
    //     end
    //     else if(swb[3] == 1'b1 && swb[6] == 1'b1)begin
    //         ALU_OP[3:0] <= sw[1:4];
    //         SHIFT_OP[2:0] <= sw[6:8];
    //         Shift_Num[7:0] <= sw[9:16]; 
    //     end
    //     else if(swb[6] == 1'b1)begin
    //         datatube <= F;        
    //     end
    // end
    
    // barrelshifter32 BB2(
    //     .Shift_Data(Shift_Data),
    //     .Shift_Num(Shift_Num),
    //     .Carry_flag(NZCV[1]),
    //     .SHIFT_OP(SHIFT_OP),
    //     .Shift_out(Shift_out),
    //     .Shift_carry_out(Shift_carry_out)
    // );
    
    // ALU A2(
    //     .A(A),
    //     .B(Shift_out),
    //     .ALU_OP(ALU_OP),
    //     .shiftCout(Shift_carry_out),
    //     .C(NZCV[1]),
    //     .V(NZCV[0]),
    //     .F(F),
    //     .NZCV(ALU_NZCV)
    // );
        
    // Display Display_Instance(.clk(clk), .data(datatube),
    //     .which(which), .seg(seg));

    
//    assign toggle = |swb; //?
//    always @(posedge toggle) enable <= ~enable;

//register
    reg [3:0]r_addr_a;
    reg [3:0]r_addr_b;
    reg [3:0]r_addr_c;
    reg [3:0]w_addr;
    reg [31:0]w_data;
    reg write_reg;
    reg write_pc;
    reg [31:0]pc_data;
    reg [4:0]M;
    wire rst;
    reg clk_reg;
    wire [31:0]r_data_a;
    wire [31:0]r_data_b;
    wire [31:0]r_data_c;
    reg [1:0]swb1_c;
    reg [3:0]swb6_c;
    reg [31:0] datatube;

    assign led[1:2] = swb1_c;
    assign led[30:32] = swb6_c;
    assign led[9] = clk_reg;
    assign led[10] = swb[3];
    assign rst = swb[3];

    always@(posedge swb[1])begin
        swb1_c <= swb1_c+1;
    end
    always@(posedge swb[6])begin
        if(swb6_c<5)begin
            swb6_c <= swb6_c+1;        
        end
        else begin
            swb6_c<=0;
        end
    end
    always @(*) begin
        if(swb[2]==1)begin
            case(swb1_c)
                2'b01:begin
                    r_addr_a<=sw[1:4];
                    r_addr_b<=sw[5:8];
                    r_addr_c<=sw[9:12];
                    M[4:0]<=sw[13:17];
                    w_addr<=sw[21:24];
                    write_reg<=sw[31];
                    write_pc<=sw[32];
                end
                2'b10:w_data<=sw[1:32];
                2'b11:pc_data<=sw[1:32];
            endcase
        end
        if(swb[6]==1)begin
            case(swb6_c)
                3'b001:datatube[31:0]<=r_data_a[31:0];
                3'b010:datatube[31:0]<=r_data_b[31:0];
                3'b011:datatube[31:0]<=r_data_c[31:0];
                3'b100:datatube[31:0]<=pc_data[31:0];
                3'b101:datatube[31:0]<='h8888_8888;
            endcase
        end
        if(swb[5]==1)begin   //show data of swb[2] set
           case(swb1_c)
                2'b01:datatube[31:0]<={r_addr_a,r_addr_b,r_addr_c,3'b000,M,w_addr,6'b000000,write_reg,write_pc};
                2'b10:datatube[31:0]<=w_data;
                2'b11:datatube[31:0]<=pc_data;
           endcase 
        end
        if(rst==1)begin
            r_addr_a<=0;
            r_addr_b<=0;
            r_addr_c<=0;
            M[4:0]<=0;
            w_addr<=0;
            write_reg<=0;
            write_pc<=0;
        end
    end
    always @(posedge swb[4]) begin
        clk_reg<=~clk_reg;
    end

    registers Regs(
        .r_addr_a(r_addr_a),
        .r_addr_b(r_addr_b),
        .r_addr_c(r_addr_c),
        .w_addr(w_addr),
        .w_data(w_data),
        .write_reg(write_reg),
        .write_pc(write_pc),
        .pc_data(pc_data),
        .M(M),
        .clk(clk_reg),
        .rst(rst),

        .r_data_a(r_data_a),
        .r_data_b(r_data_b),
        .r_data_c(r_data_c)
    );
    Display Display_Instance(.clk(clk), .data(datatube),
        .which(which), .seg(seg));
endmodule //
