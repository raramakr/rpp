#ifndef RPP_CL_IMGAUG_DECLATAIONS_H
#define RPP_CL_IMGAUG_DECLATAIONS_H

// ===== Utils

cl_int
cl_kernel_initializer ( cl_command_queue theQueue,
                        std::string kernelFile, std::string kernelName,
                        cl_program& theProgram, cl_kernel& theKernel);

cl_int
cl_kernel_implementer (cl_command_queue theHandle, size_t* gDim3, size_t* lDim3, cl_program& theProgram,
                        cl_kernel& theKernel  );

bool SaveProgramBinary(cl_program program, cl_device_id device, const std::string fileName);

cl_int CreateProgramFromBinary(cl_command_queue theQueue, const std::string kernelFile,
                                const std::string binaryFile, std::string kernelName,
                                cl_program& theProgram, cl_kernel& theKernel);

//===== Internal CL functions

RppStatus
brightness_cl (    cl_mem srcPtr, RppiSize srcSize,
                            cl_mem dstPtr,
                            Rpp32f alpha, Rpp32s beta,
                            RppiChnFormat chnFormat, unsigned int channel,
                            cl_command_queue theQueue);

RppStatus
contrast_cl (    cl_mem srcPtr, RppiSize srcSize,
                            cl_mem dstPtr,
                            Rpp32u newMin, Rpp32u newMax,
                            RppiChnFormat chnFormat, unsigned int channel,
                            cl_command_queue theQueue);
cl_int
blur_cl(cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, unsigned int filterSize,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);
cl_int
flip_cl(cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, RppiAxis flipAxis,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

RppStatus
hueRGB_cl (cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, Rpp32f hue, Rpp32f Saturation,
                RppiChnFormat chnFormat, unsigned int channel, cl_command_queue theQueue);

RppStatus
gamma_correction_cl ( cl_mem srcPtr1, RppiSize srcSize,
                 cl_mem dstPtr,float gamma,
                 RppiChnFormat chnFormat, unsigned int channel,
                 cl_command_queue theQueue);

cl_int
resize_cl(cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, RppiSize dstSize,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

cl_int
resize_crop_cl(cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, RppiSize dstSize,
                Rpp32u x1, Rpp32u y1, Rpp32u x2, Rpp32u y2, Rpp32u padding, Rpp32u type,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

cl_int
rotate_cl(cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, RppiSize dstSize, float angleDeg,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

RppStatus
blend_cl( cl_mem srcPtr1,cl_mem srcPtr2,
                 RppiSize srcSize, cl_mem dstPtr, float alpha,
                 RppiChnFormat chnFormat, unsigned int channel,
                 cl_command_queue theQueue);

cl_int
pixelate_cl(cl_mem srcPtr, RppiSize srcSize,cl_mem dstPtr,
            RppiChnFormat chnFormat,
            unsigned int channel,cl_command_queue theQueue);

cl_int
jitter_cl( cl_mem srcPtr,RppiSize srcSize, cl_mem dstPtr,
           unsigned int KernelSize,
           RppiChnFormat chnFormat, unsigned int channel,
           cl_command_queue theQueue);

cl_int
fisheye_cl(cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

cl_int
lens_correction_cl( cl_mem srcPtr,RppiSize srcSize, cl_mem dstPtr,
           float strength,float zoom,
           RppiChnFormat chnFormat, unsigned int channel,
           cl_command_queue theQueue);

cl_int
snow_cl( cl_mem srcPtr,RppiSize srcSize, cl_mem dstPtr,
           float snowCoefficient,
           RppiChnFormat chnFormat, unsigned int channel,
           cl_command_queue theQueue);

RppStatus
snpNoise_cl(cl_mem srcPtr,
                RppiSize srcSize,
                cl_mem dstPtr,
                Rpp32f noiseProbability,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

RppStatus
color_temperature_cl( cl_mem srcPtr1,
                 RppiSize srcSize, cl_mem dstPtr, float adjustmentValue,
                 RppiChnFormat chnFormat, unsigned int channel,
                 cl_command_queue theQueue);

RppStatus
rain_cl(    cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, Rpp32f rainPercentage, Rpp32u rainWidth, Rpp32u rainHeight, Rpp32f transparency,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

RppStatus
vignette_cl( cl_mem srcPtr1, RppiSize srcSize,
                cl_mem dstPtr, float stdDev,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

RppStatus
fog_cl( cl_mem srcPtr, RppiSize srcSize,
                Rpp32f fogValue,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue, cl_mem temp);


cl_int
warp_affine_cl(cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, RppiSize dstSize, float *affine,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

RppStatus
exposure_cl(    cl_mem srcPtr, RppiSize srcSize,
                cl_mem dstPtr, Rpp32f exposureValue,
                RppiChnFormat chnFormat, unsigned int channel,
                cl_command_queue theQueue);

#endif //RPP_CL_IMGAUG_DECLATAIONS_H
