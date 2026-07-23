struct PixeShaderOutput
{
    float4 color : SV_TARGET;
};
PixeShaderOutput main()
{
    PixeShaderOutput output;
    output.color = float4(1.0f, 1.0f, 1.0f, 1.0f);
    return output;
}