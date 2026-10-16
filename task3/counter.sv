

module counter #(
    parameter WIDTH = 8
) (
    input logic clk,
    input logic reset,
    input logic load,
    input logic [WIDTH-1:0] val,
    output logic [WIDTH-1:0] count
);

    always_ff @(posedge clk) begin
        if (reset) begin
            count <= {WIDTH{1'b0}};
        end
        else begin
            count <= load ? val : count + {{WIDTH-1{1'b0}}, 1'b1};
        end
    end


endmodule



