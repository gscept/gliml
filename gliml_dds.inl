//------------------------------------------------------------------------------
//  gliml_dds.inl
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
inline bool
is_dds(const void* data, unsigned int byteSize) {
    if (byteSize > sizeof(dds_header)) {
        const dds_header* hdr = (const dds_header*)data;
        return hdr->dwMagicFourCC == ' SDD';
    }
    return false;
}

inline bool
is_dds_dx10(const dds_header* hdr) {
    return hdr->ddspf.dwFlags & GLIML_DDSF_FOURCC && hdr->ddspf.dwFourCC == GLIML_FOURCC_DXT10;
}


inline int
bytes_per_element_DXGI(DXGI_FORMAT format) {
    switch (format) {
    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
    case DXGI_FORMAT_R32G32B32A32_UINT:
    case DXGI_FORMAT_R32G32B32A32_SINT:
    case DXGI_FORMAT_BC2_TYPELESS:
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC2_UNORM_SRGB:
    case DXGI_FORMAT_BC3_TYPELESS:
    case DXGI_FORMAT_BC3_UNORM:
    case DXGI_FORMAT_BC3_UNORM_SRGB:
    case DXGI_FORMAT_BC5_TYPELESS:
    case DXGI_FORMAT_BC5_UNORM:
    case DXGI_FORMAT_BC5_SNORM:
    case DXGI_FORMAT_BC6H_TYPELESS:
    case DXGI_FORMAT_BC6H_UF16:
    case DXGI_FORMAT_BC6H_SF16:
    case DXGI_FORMAT_BC7_TYPELESS:
    case DXGI_FORMAT_BC7_UNORM:
    case DXGI_FORMAT_BC7_UNORM_SRGB:
        return 16;

    case DXGI_FORMAT_R32G32B32_TYPELESS:
    case DXGI_FORMAT_R32G32B32_FLOAT:
    case DXGI_FORMAT_R32G32B32_UINT:
    case DXGI_FORMAT_R32G32B32_SINT:
        return 12;

    case DXGI_FORMAT_R16G16B16A16_TYPELESS:
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_UNORM:
    case DXGI_FORMAT_R16G16B16A16_UINT:
    case DXGI_FORMAT_R16G16B16A16_SNORM:
    case DXGI_FORMAT_R16G16B16A16_SINT:
    case DXGI_FORMAT_R32G32_TYPELESS:
    case DXGI_FORMAT_R32G32_FLOAT:
    case DXGI_FORMAT_R32G32_UINT:
    case DXGI_FORMAT_R32G32_SINT:
    case DXGI_FORMAT_R32G8X24_TYPELESS:
    case DXGI_FORMAT_Y416:
    case DXGI_FORMAT_Y210:
    case DXGI_FORMAT_Y216:
    case DXGI_FORMAT_BC1_TYPELESS:
    case DXGI_FORMAT_BC1_UNORM:
    case DXGI_FORMAT_BC1_UNORM_SRGB:
    case DXGI_FORMAT_BC4_UNORM:
    case DXGI_FORMAT_BC4_SNORM:
    case DXGI_FORMAT_BC4_TYPELESS:
        return 8;

    case DXGI_FORMAT_R8G8_TYPELESS:
    case DXGI_FORMAT_R8G8_UNORM:
    case DXGI_FORMAT_R8G8_UINT:
    case DXGI_FORMAT_R8G8_SNORM:
    case DXGI_FORMAT_R8G8_SINT:
    case DXGI_FORMAT_R16_TYPELESS:
    case DXGI_FORMAT_R16_FLOAT:
    case DXGI_FORMAT_D16_UNORM:
    case DXGI_FORMAT_R16_UNORM:
    case DXGI_FORMAT_R16_UINT:
    case DXGI_FORMAT_R16_SNORM:
    case DXGI_FORMAT_R16_SINT:
    case DXGI_FORMAT_B5G6R5_UNORM:
    case DXGI_FORMAT_B5G5R5A1_UNORM:
    case DXGI_FORMAT_P010:
    case DXGI_FORMAT_P016:
    case DXGI_FORMAT_A8P8:
    case DXGI_FORMAT_B4G4R4A4_UNORM:
        return 2;

    case DXGI_FORMAT_R8_TYPELESS:
    case DXGI_FORMAT_R8_UNORM:
    case DXGI_FORMAT_R8_UINT:
    case DXGI_FORMAT_R8_SNORM:
    case DXGI_FORMAT_R8_SINT:
    case DXGI_FORMAT_A8_UNORM:
    case DXGI_FORMAT_NV12:
    case DXGI_FORMAT_420_OPAQUE:
    case DXGI_FORMAT_NV11:
    case DXGI_FORMAT_AI44:
    case DXGI_FORMAT_IA44:
    case DXGI_FORMAT_P8:
    case DXGI_FORMAT_P208:
    case DXGI_FORMAT_V208:
    case DXGI_FORMAT_V408:
        return 1;

    case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
    case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
    case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
    case DXGI_FORMAT_R10G10B10A2_TYPELESS:
    case DXGI_FORMAT_R10G10B10A2_UNORM:
    case DXGI_FORMAT_R10G10B10A2_UINT:
    case DXGI_FORMAT_R11G11B10_FLOAT:
    case DXGI_FORMAT_R8G8B8A8_TYPELESS:
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
    case DXGI_FORMAT_R8G8B8A8_UINT:
    case DXGI_FORMAT_R8G8B8A8_SNORM:
    case DXGI_FORMAT_R8G8B8A8_SINT:
    case DXGI_FORMAT_R16G16_TYPELESS:
    case DXGI_FORMAT_R16G16_FLOAT:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R16G16_UINT:
    case DXGI_FORMAT_R16G16_SNORM:
    case DXGI_FORMAT_R16G16_SINT:
    case DXGI_FORMAT_R32_TYPELESS:
    case DXGI_FORMAT_D32_FLOAT:
    case DXGI_FORMAT_R32_FLOAT:
    case DXGI_FORMAT_R32_UINT:
    case DXGI_FORMAT_R32_SINT:
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
    case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
    case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
    case DXGI_FORMAT_B8G8R8A8_UNORM:
    case DXGI_FORMAT_B8G8R8X8_UNORM:
    case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
    case DXGI_FORMAT_B8G8R8A8_TYPELESS:
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
    case DXGI_FORMAT_B8G8R8X8_TYPELESS:
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
    case DXGI_FORMAT_AYUV:
    case DXGI_FORMAT_Y410:
    case DXGI_FORMAT_YUY2:
    case DXGI_FORMAT_R24G8_TYPELESS:
    case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
        return 4;

    case DXGI_FORMAT_R1_UNORM:
    case DXGI_FORMAT_FORCE_UINT:
    case DXGI_FORMAT_UNKNOWN:
    case DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE:
    case DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE:
        GLIML_ASSERT("Unsupported texture format");
        return 0;
    }
    GLIML_ASSERT("Missing DXGI Enum");
    return 0;
}

inline bool
is_compressed_DXGI(DXGI_FORMAT format) {
    switch (format) {
    case DXGI_FORMAT_BC1_TYPELESS:
    case DXGI_FORMAT_BC1_UNORM:
    case DXGI_FORMAT_BC1_UNORM_SRGB:
    case DXGI_FORMAT_BC4_UNORM:
    case DXGI_FORMAT_BC4_SNORM:
    case DXGI_FORMAT_BC4_TYPELESS:
    case DXGI_FORMAT_BC2_TYPELESS:
    case DXGI_FORMAT_BC2_UNORM:
    case DXGI_FORMAT_BC2_UNORM_SRGB:
    case DXGI_FORMAT_BC3_TYPELESS:
    case DXGI_FORMAT_BC3_UNORM:
    case DXGI_FORMAT_BC3_UNORM_SRGB:
    case DXGI_FORMAT_BC5_TYPELESS:
    case DXGI_FORMAT_BC5_UNORM:
    case DXGI_FORMAT_BC5_SNORM:
    case DXGI_FORMAT_BC6H_TYPELESS:
    case DXGI_FORMAT_BC6H_UF16:
    case DXGI_FORMAT_BC6H_SF16:
    case DXGI_FORMAT_BC7_TYPELESS:
    case DXGI_FORMAT_BC7_UNORM:
    case DXGI_FORMAT_BC7_UNORM_SRGB:
        return true;

    case DXGI_FORMAT_R32G32B32A32_TYPELESS:
    case DXGI_FORMAT_R32G32B32A32_FLOAT:
    case DXGI_FORMAT_R32G32B32A32_UINT:
    case DXGI_FORMAT_R32G32B32A32_SINT:
    case DXGI_FORMAT_R32G32B32_TYPELESS:
    case DXGI_FORMAT_R32G32B32_FLOAT:
    case DXGI_FORMAT_R32G32B32_UINT:
    case DXGI_FORMAT_R32G32B32_SINT:
    case DXGI_FORMAT_R16G16B16A16_TYPELESS:
    case DXGI_FORMAT_R16G16B16A16_FLOAT:
    case DXGI_FORMAT_R16G16B16A16_UNORM:
    case DXGI_FORMAT_R16G16B16A16_UINT:
    case DXGI_FORMAT_R16G16B16A16_SNORM:
    case DXGI_FORMAT_R16G16B16A16_SINT:
    case DXGI_FORMAT_R32G32_TYPELESS:
    case DXGI_FORMAT_R32G32_FLOAT:
    case DXGI_FORMAT_R32G32_UINT:
    case DXGI_FORMAT_R32G32_SINT:
    case DXGI_FORMAT_R32G8X24_TYPELESS:
    case DXGI_FORMAT_Y416:
    case DXGI_FORMAT_Y210:
    case DXGI_FORMAT_Y216:
    case DXGI_FORMAT_R8G8_TYPELESS:
    case DXGI_FORMAT_R8G8_UNORM:
    case DXGI_FORMAT_R8G8_UINT:
    case DXGI_FORMAT_R8G8_SNORM:
    case DXGI_FORMAT_R8G8_SINT:
    case DXGI_FORMAT_R16_TYPELESS:
    case DXGI_FORMAT_R16_FLOAT:
    case DXGI_FORMAT_D16_UNORM:
    case DXGI_FORMAT_R16_UNORM:
    case DXGI_FORMAT_R16_UINT:
    case DXGI_FORMAT_R16_SNORM:
    case DXGI_FORMAT_R16_SINT:
    case DXGI_FORMAT_B5G6R5_UNORM:
    case DXGI_FORMAT_B5G5R5A1_UNORM:
    case DXGI_FORMAT_P010:
    case DXGI_FORMAT_P016:
    case DXGI_FORMAT_A8P8:
    case DXGI_FORMAT_B4G4R4A4_UNORM:
    case DXGI_FORMAT_R8_TYPELESS:
    case DXGI_FORMAT_R8_UNORM:
    case DXGI_FORMAT_R8_UINT:
    case DXGI_FORMAT_R8_SNORM:
    case DXGI_FORMAT_R8_SINT:
    case DXGI_FORMAT_A8_UNORM:
    case DXGI_FORMAT_NV12:
    case DXGI_FORMAT_420_OPAQUE:
    case DXGI_FORMAT_NV11:
    case DXGI_FORMAT_AI44:
    case DXGI_FORMAT_IA44:
    case DXGI_FORMAT_P8:
    case DXGI_FORMAT_P208:
    case DXGI_FORMAT_V208:
    case DXGI_FORMAT_V408:
    case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
    case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS:
    case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT:
    case DXGI_FORMAT_R10G10B10A2_TYPELESS:
    case DXGI_FORMAT_R10G10B10A2_UNORM:
    case DXGI_FORMAT_R10G10B10A2_UINT:
    case DXGI_FORMAT_R11G11B10_FLOAT:
    case DXGI_FORMAT_R8G8B8A8_TYPELESS:
    case DXGI_FORMAT_R8G8B8A8_UNORM:
    case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
    case DXGI_FORMAT_R8G8B8A8_UINT:
    case DXGI_FORMAT_R8G8B8A8_SNORM:
    case DXGI_FORMAT_R8G8B8A8_SINT:
    case DXGI_FORMAT_R16G16_TYPELESS:
    case DXGI_FORMAT_R16G16_FLOAT:
    case DXGI_FORMAT_R16G16_UNORM:
    case DXGI_FORMAT_R16G16_UINT:
    case DXGI_FORMAT_R16G16_SNORM:
    case DXGI_FORMAT_R16G16_SINT:
    case DXGI_FORMAT_R32_TYPELESS:
    case DXGI_FORMAT_D32_FLOAT:
    case DXGI_FORMAT_R32_FLOAT:
    case DXGI_FORMAT_R32_UINT:
    case DXGI_FORMAT_R32_SINT:
    case DXGI_FORMAT_D24_UNORM_S8_UINT:
    case DXGI_FORMAT_R24_UNORM_X8_TYPELESS:
    case DXGI_FORMAT_X24_TYPELESS_G8_UINT:
    case DXGI_FORMAT_B8G8R8A8_UNORM:
    case DXGI_FORMAT_B8G8R8X8_UNORM:
    case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM:
    case DXGI_FORMAT_B8G8R8A8_TYPELESS:
    case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
    case DXGI_FORMAT_B8G8R8X8_TYPELESS:
    case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
    case DXGI_FORMAT_AYUV:
    case DXGI_FORMAT_Y410:
    case DXGI_FORMAT_YUY2:
    case DXGI_FORMAT_R24G8_TYPELESS:
    case DXGI_FORMAT_R9G9B9E5_SHAREDEXP:
    case DXGI_FORMAT_R8G8_B8G8_UNORM:
    case DXGI_FORMAT_G8R8_G8B8_UNORM:
        return false;

    case DXGI_FORMAT_R1_UNORM:
    case DXGI_FORMAT_FORCE_UINT:
    case DXGI_FORMAT_UNKNOWN:
    case DXGI_FORMAT_SAMPLER_FEEDBACK_MIN_MIP_OPAQUE:
    case DXGI_FORMAT_SAMPLER_FEEDBACK_MIP_REGION_USED_OPAQUE:
        GLIML_ASSERT("Unsupported texture format");
        return false;
    }
    GLIML_ASSERT("Missing DXGI Enum");
    return 0;
}


//------------------------------------------------------------------------------
inline bool
context::load_dds(const void* data, unsigned int byteSize) {
    GLIML_ASSERT(gliml::is_dds(data, byteSize));
    this->clear();

    const dds_header* hdr = (const dds_header*)data;
    const unsigned char* dataBytePtr = (const unsigned char*)hdr;
    dataBytePtr += sizeof(dds_header);

    const dds_header_dxt10* hdr_dx10 = nullptr;
    if (is_dds_dx10(hdr)) {
        hdr_dx10 = (const dds_header_dxt10*)dataBytePtr;
        dataBytePtr += sizeof(dds_header_dxt10);
    }

    // cubemap?
    bool isCubeMap = false;
    if (GLIML_DDSF_CUBEMAP & hdr->dwCaps2) {
        this->target = GLIML_GL_TEXTURE_CUBE_MAP;
        this->is2D = true;
        this->is3D = false;
        this->numFaces = 6;
        isCubeMap = true;
    }
    // 3D texture?
    else if ((GLIML_DDSF_VOLUME & hdr->dwCaps2) && (hdr->dwDepth > 0)) {
        this->target = GLIML_GL_TEXTURE_3D;
        this->is2D = false;
        this->is3D = true;
        this->numFaces = 1;
    }
    // 2D texture
    else {
        this->target = GLIML_GL_TEXTURE_2D;
        this->is2D = true;
        this->is3D = false;
        this->numFaces = 1;
    }

    // image format
    int bytesPerElement = 0;
    if (hdr->ddspf.dwFlags & GLIML_DDSF_FOURCC) {
        // test if DXT compressed formats are supported by GL implementation
        if (!this->dxtEnabled) {
            this->errorCode = GLIML_ERROR_DXT_NOT_ENABLED;
            return false;
        }
        switch (hdr->ddspf.dwFourCC) {
            case GLIML_FOURCC_DXT1:
                this->format = this->internalFormat = GLIML_GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
                this->isCompressed = true;
                bytesPerElement = 8;
                break;
            case GLIML_FOURCC_BC4S:
                this->format = this->internalFormat = GLIML_FOURCC_BC4S;
                this->isCompressed = true;
                bytesPerElement = 8;
                break;
            case GLIML_FOURCC_ATI1:
            case GLIML_FOURCC_BC4U:
                this->format = this->internalFormat = GLIML_FOURCC_BC4U;
                this->isCompressed = true;
                bytesPerElement = 8;
                break;
            case GLIML_FOURCC_DXT3:
                this->format = this->internalFormat = GLIML_GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
                this->isCompressed = true;
                bytesPerElement = 16;
                break;
            case GLIML_FOURCC_DXT5:
                this->format = this->internalFormat = GLIML_GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
                this->isCompressed = true;
                bytesPerElement = 16;
                break;
            case GLIML_FOURCC_DXT5_xGxR:
                this->format = this->internalFormat = GLIML_FOURCC_DXT5_xGxR;
                this->isCompressed = true;
                bytesPerElement = 16;
                break;
            case GLIML_FOURCC_BC5S:
                this->format = this->internalFormat = GLIML_FOURCC_BC5S;
                this->isCompressed = true;
                bytesPerElement = 16;
                break;

            case GLIML_FOURCC_DXT10:
                this->format = GLIML_FOURCC_DXT10;
                this->internalFormat = hdr_dx10->dwDxgiFormat;
                this->isCompressed = is_compressed_DXGI((DXGI_FORMAT)hdr_dx10->dwDxgiFormat);
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)hdr_dx10->dwDxgiFormat);
                break;
            // these are pseudo dx10 types, use same mechanic as for those and pretend they are
            case GLIML_FOURCC_ATI2:
            case GLIML_FOURCC_BC5U:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = true;
                this->internalFormat = DXGI_FORMAT_BC5_UNORM;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_R16G16B16A16_UNORM:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R16G16B16A16_UNORM;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_R16G16B16A16_SNORM:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R16G16B16A16_SNORM;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_R16_FLOAT:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R16_FLOAT;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_R16G16:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R16G16_FLOAT;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_R16G16B16A16:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R16G16B16A16_FLOAT;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_R32_FLOAT:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R32_FLOAT;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_R32G32_FLOAT:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R32G32_FLOAT;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_R32G32B32A32_FLOAT:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R32G32B32A32_FLOAT;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            case GLIML_FOURCC_L16:
                this->format = GLIML_FOURCC_DXT10;
                this->isCompressed = false;
                this->internalFormat = DXGI_FORMAT_R16_UINT;
                bytesPerElement = bytes_per_element_DXGI((DXGI_FORMAT)this->internalFormat);
                break;
            default:
                this->errorCode = GLIML_ERROR_INVALID_COMPRESSED_FORMAT;
                return false;
        }
    }
    else if ((hdr->ddspf.dwFlags & (GLIML_DDSF_RGBA|GLIML_DDSF_RGB)) && (hdr->ddspf.dwRGBBitCount == 32)) {
        // 32-bit RGBA, check byte order
        bytesPerElement = 4;
        this->type = GLIML_GL_UNSIGNED_BYTE;
        this->internalFormat = GLIML_GL_RGBA;
        if (hdr->ddspf.dwRBitMask == 0x00FF0000) {
            // Direct3D style BGRA
            if (this->bgraEnabled) {
                this->format = GLIML_GL_BGRA;
            }
            else {
                this->errorCode = GLIML_ERROR_BGRA_NOT_ENABLED;
                return false;
            }
        }
        else {
            // OpenGLES style RGBA
            this->format = GLIML_GL_RGBA;
        }
    }
    else if ((hdr->ddspf.dwFlags & GLIML_DDSF_RGB) && (hdr->ddspf.dwRGBBitCount == 24)) {
        // 24-bit RGB, check byte order
        bytesPerElement = 3;
        this->type = GLIML_GL_UNSIGNED_BYTE;
        this->internalFormat = GLIML_GL_RGB;
        if (hdr->ddspf.dwRBitMask == 0x00FF0000) {
            // Direct3D style BGR
            if (this->bgraEnabled) {
                this->format = GLIML_GL_BGR;
            }
            else {
                this->errorCode = GLIML_ERROR_BGRA_NOT_ENABLED;
                return false;
            }
        }
        else {
            // OpenGLES style RGB
            this->format = GLIML_GL_RGB;
        }
    }
    else if (hdr->ddspf.dwRGBBitCount == 16) {
        // 16-bit RGB(A)
        bytesPerElement = 2;
        if (hdr->ddspf.dwABitMask == 0) {
            // RGB565 or BGR565
            this->type = GLIML_GL_UNSIGNED_SHORT_5_6_5;
            this->internalFormat = GLIML_GL_RGB;
            if (hdr->ddspf.dwRBitMask == (0x1F << 11)) {
                // Direct3D style 
                if (this->bgraEnabled) {
                    this->format = GLIML_GL_BGR;
                }
                else {
                    this->errorCode = GLIML_ERROR_BGRA_NOT_ENABLED;
                    return false;
                }
            }
            else {
                // OpenGLES style
                this->format = GLIML_GL_RGB;
            }
        }
        else {
            // RGBA4 or BGRA4 or RGBA5551 or BGRA5551
            this->internalFormat = GLIML_GL_RGBA;
            if (hdr->ddspf.dwRBitMask == 0x00F0) {
                // Direct3D style bgra4
                if (this->bgraEnabled) {
                    this->type = GLIML_GL_UNSIGNED_SHORT_4_4_4_4;
                    this->format = GLIML_GL_BGRA;
                }
                else {
                    this->errorCode = GLIML_ERROR_BGRA_NOT_ENABLED;
                    return false;
                }
            }
            else if (hdr->ddspf.dwRBitMask == 0xF000) {
                // OpenGLES style rgba4
                this->type = GLIML_GL_UNSIGNED_SHORT_4_4_4_4;
                this->format = GLIML_GL_RGBA;
            }
            else if (hdr->ddspf.dwRBitMask == (0x1F << 1)) {
                // Direc3D style bgra5551
                if (this->bgraEnabled) {
                    this->type = GLIML_GL_UNSIGNED_SHORT_5_5_5_1;
                    this->format = GLIML_GL_BGRA;
                }
                else {
                    this->errorCode = GLIML_ERROR_BGRA_NOT_ENABLED;
                    return false;
                }
            }
            else {
                // OpenGLES style rgba5551
                this->type = GLIML_GL_UNSIGNED_SHORT_5_5_5_1;
                this->format = GLIML_GL_RGBA;
            }
        }
    }
    else if (hdr->ddspf.dwRGBBitCount == 8) {
        this->format = GLIML_GL_LUMINANCE;
        this->internalFormat = GLIML_GL_LUMINANCE;
        this->type = GLIML_GL_UNSIGNED_BYTE;
        bytesPerElement = 1;
    }

    // for each face...
    int faceIndex;
    for (faceIndex = 0; faceIndex < this->numFaces; faceIndex++) {
        face& curFace = this->faces[faceIndex];
        if (isCubeMap) {
            switch (faceIndex) {
                case 0:     curFace.target = GLIML_GL_TEXTURE_CUBE_MAP_POSITIVE_X; break;
                case 1:     curFace.target = GLIML_GL_TEXTURE_CUBE_MAP_NEGATIVE_X; break;
                case 2:     curFace.target = GLIML_GL_TEXTURE_CUBE_MAP_POSITIVE_Y; break;
                case 3:     curFace.target = GLIML_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y; break;
                case 4:     curFace.target = GLIML_GL_TEXTURE_CUBE_MAP_POSITIVE_Z; break;
                default:    curFace.target = GLIML_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z; break;
            }
        }
        else {
            curFace.target = this->target;
        }
        curFace.numMipmaps = (hdr->dwMipMapCount == 0) ? 1 : hdr->dwMipMapCount;

        // for each mipmap
        int mipIndex;
        for (mipIndex = 0; mipIndex < curFace.numMipmaps; mipIndex++) {
            face::mipmap& curMip = curFace.mipmaps[mipIndex];

            // mipmap dimensions
            int w = hdr->dwWidth >> mipIndex;
            if (w <= 0) w = 1;
            int h = hdr->dwHeight >> mipIndex;
            if (h <= 0) h = 1;
            int d = hdr->dwDepth >> mipIndex;
            if (d <= 0) d = 1;
            curMip.width = w;
            curMip.height = h;
            curMip.depth = d;

            // mipmap byte size
            if (this->isCompressed) {
                curMip.size = ((w+3)/4) * ((h+3)/4) * d * bytesPerElement;
            }
            else {
                curMip.size = w * h * d * bytesPerElement;
            }

            // set and advance surface data pointer
            curMip.data = dataBytePtr;
            dataBytePtr += curMip.size;
        }
    }
    GLIML_ASSERT(dataBytePtr == ((const unsigned char*)data) + byteSize);

    // ...and we're done
    return true;
}
