

module counter #(
    parameter WIDTH = 8
) (
    input logic clk,
    input logic reset,
    input logic enable,
    output logic [WIDTH-1:0] count
);

    always_ff @(posedge clk, posedge reset) begin
        if (reset) begin
            count <= {WIDTH{1'b0}};
        end
        else begin
            count <= count + {{WIDTH-1{!enable}}, 1'b1}; // choosing direction to count based on enable
        end
    end


endmodule



