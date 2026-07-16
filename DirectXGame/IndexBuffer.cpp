#include "IndexBuffer.h"
#include "KamataEngine.h"

#include <d3d12.h>
#include <cassert>

using namespace KamataEngine;

//生成　
void IndexBuffer::Create(const UINT size, const UINT stride) {
	//strideの値によって、1つのインデックスのフォーマットを決める
	assert(stride == 2 || stride == 4);
	DXGI_FORMAT format = (stride == 2) ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT;
	 //クラス内でdxCommonを利用するために追加
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();
	// インデックスリソースの生成 ============================
	// インデックスリソース用のヒープの設定
	D3D12_HEAP_PROPERTIES uploadHeapProperties{};
	uploadHeapProperties.Type = D3D