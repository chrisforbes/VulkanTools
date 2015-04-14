/* Need to define dispatch table
 * Core struct can then have ptr to dispatch table at the top
 * Along with object ptrs for current and next OBJ
 */
#pragma once

#include "vulkan.h"
#include "vkDbg.h"
#if defined(__linux__) || defined(XCB_NVIDIA)
#include "vkWsiX11Ext.h"
#endif
#if defined(__GNUC__) && __GNUC__ >= 4
#  define VK_LAYER_EXPORT __attribute__((visibility("default")))
#elif defined(__SUNPRO_C) && (__SUNPRO_C >= 0x590)
#  define VK_LAYER_EXPORT __attribute__((visibility("default")))
#else
#  define VK_LAYER_EXPORT
#endif


typedef struct VkBaseLayerObject_
{
    PFN_vkGetProcAddr pGPA;
    VkBaseObject nextObject;
    VkBaseObject baseObject;
} VkBaseLayerObject;

typedef struct VkLayerDispatchTable_
{
    PFN_vkGetProcAddr GetProcAddr;
    PFN_vkCreateInstance CreateInstance;
    PFN_vkDestroyInstance DestroyInstance;
    PFN_vkEnumerateGpus EnumerateGpus;
    PFN_vkGetGpuInfo GetGpuInfo;
    PFN_vkCreateDevice CreateDevice;
    PFN_vkDestroyDevice DestroyDevice;
    PFN_vkGetGlobalExtensionInfo GetGlobalExtensionInfo;
    PFN_vkGetExtensionSupport GetExtensionSupport;
    PFN_vkEnumerateLayers EnumerateLayers;
    PFN_vkGetDeviceQueue GetDeviceQueue;
    PFN_vkQueueSubmit QueueSubmit;
    PFN_vkQueueAddMemReference QueueAddMemReference;
    PFN_vkQueueRemoveMemReference QueueRemoveMemReference;
    PFN_vkQueueWaitIdle QueueWaitIdle;
    PFN_vkDeviceWaitIdle DeviceWaitIdle;
    PFN_vkAllocMemory AllocMemory;
    PFN_vkFreeMemory FreeMemory;
    PFN_vkSetMemoryPriority SetMemoryPriority;
    PFN_vkMapMemory MapMemory;
    PFN_vkUnmapMemory UnmapMemory;
    PFN_vkPinSystemMemory PinSystemMemory;
    PFN_vkGetMultiGpuCompatibility GetMultiGpuCompatibility;
    PFN_vkOpenSharedMemory OpenSharedMemory;
    PFN_vkOpenSharedSemaphore OpenSharedSemaphore;
    PFN_vkOpenPeerMemory OpenPeerMemory;
    PFN_vkOpenPeerImage OpenPeerImage;
    PFN_vkDestroyObject DestroyObject;
    PFN_vkGetObjectInfo GetObjectInfo;
    PFN_vkBindObjectMemory BindObjectMemory;
    PFN_vkBindObjectMemoryRange BindObjectMemoryRange;
    PFN_vkBindImageMemoryRange BindImageMemoryRange;
    PFN_vkCreateFence CreateFence;
    PFN_vkGetFenceStatus GetFenceStatus;
    PFN_vkResetFences ResetFences;
    PFN_vkWaitForFences WaitForFences;
    PFN_vkCreateSemaphore CreateSemaphore;
    PFN_vkQueueSignalSemaphore QueueSignalSemaphore;
    PFN_vkQueueWaitSemaphore QueueWaitSemaphore;
    PFN_vkCreateEvent CreateEvent;
    PFN_vkGetEventStatus GetEventStatus;
    PFN_vkSetEvent SetEvent;
    PFN_vkResetEvent ResetEvent;
    PFN_vkCreateQueryPool CreateQueryPool;
    PFN_vkGetQueryPoolResults GetQueryPoolResults;
    PFN_vkGetFormatInfo GetFormatInfo;
    PFN_vkCreateBuffer CreateBuffer;
    PFN_vkCreateBufferView CreateBufferView;
    PFN_vkCreateImage CreateImage;
    PFN_vkGetImageSubresourceInfo GetImageSubresourceInfo;
    PFN_vkCreateImageView CreateImageView;
    PFN_vkCreateColorAttachmentView CreateColorAttachmentView;
    PFN_vkCreateDepthStencilView CreateDepthStencilView;
    PFN_vkCreateShader CreateShader;
    PFN_vkCreateGraphicsPipeline CreateGraphicsPipeline;
    PFN_vkCreateGraphicsPipelineDerivative CreateGraphicsPipelineDerivative;
    PFN_vkCreateComputePipeline CreateComputePipeline;
    PFN_vkStorePipeline StorePipeline;
    PFN_vkLoadPipeline LoadPipeline;
    PFN_vkLoadPipelineDerivative LoadPipelineDerivative;
    PFN_vkCreateSampler CreateSampler;
    PFN_vkCreateDescriptorSetLayout CreateDescriptorSetLayout;
    PFN_vkCreateDescriptorSetLayoutChain CreateDescriptorSetLayoutChain;
    PFN_vkBeginDescriptorPoolUpdate BeginDescriptorPoolUpdate;
    PFN_vkEndDescriptorPoolUpdate EndDescriptorPoolUpdate;
    PFN_vkCreateDescriptorPool CreateDescriptorPool;
    PFN_vkResetDescriptorPool ResetDescriptorPool;
    PFN_vkAllocDescriptorSets AllocDescriptorSets;
    PFN_vkClearDescriptorSets ClearDescriptorSets;
    PFN_vkUpdateDescriptors UpdateDescriptors;
    PFN_vkCreateDynamicViewportState CreateDynamicViewportState;
    PFN_vkCreateDynamicRasterState CreateDynamicRasterState;
    PFN_vkCreateDynamicColorBlendState CreateDynamicColorBlendState;
    PFN_vkCreateDynamicDepthStencilState CreateDynamicDepthStencilState;
    PFN_vkCreateCommandBuffer CreateCommandBuffer;
    PFN_vkBeginCommandBuffer BeginCommandBuffer;
    PFN_vkEndCommandBuffer EndCommandBuffer;
    PFN_vkResetCommandBuffer ResetCommandBuffer;
    PFN_vkCmdBindPipeline CmdBindPipeline;
    PFN_vkCmdBindDynamicStateObject CmdBindDynamicStateObject;
    PFN_vkCmdBindDescriptorSets CmdBindDescriptorSets;
    PFN_vkCmdBindVertexBuffer CmdBindVertexBuffer;
    PFN_vkCmdBindIndexBuffer CmdBindIndexBuffer;
    PFN_vkCmdDraw CmdDraw;
    PFN_vkCmdDrawIndexed CmdDrawIndexed;
    PFN_vkCmdDrawIndirect CmdDrawIndirect;
    PFN_vkCmdDrawIndexedIndirect CmdDrawIndexedIndirect;
    PFN_vkCmdDispatch CmdDispatch;
    PFN_vkCmdDispatchIndirect CmdDispatchIndirect;
    PFN_vkCmdCopyBuffer CmdCopyBuffer;
    PFN_vkCmdCopyImage CmdCopyImage;
    PFN_vkCmdBlitImage CmdBlitImage;
    PFN_vkCmdCopyBufferToImage CmdCopyBufferToImage;
    PFN_vkCmdCopyImageToBuffer CmdCopyImageToBuffer;
    PFN_vkCmdCloneImageData CmdCloneImageData;
    PFN_vkCmdUpdateBuffer CmdUpdateBuffer;
    PFN_vkCmdFillBuffer CmdFillBuffer;
    PFN_vkCmdClearColorImage CmdClearColorImage;
    PFN_vkCmdClearDepthStencil CmdClearDepthStencil;
    PFN_vkCmdResolveImage CmdResolveImage;
    PFN_vkCmdSetEvent CmdSetEvent;
    PFN_vkCmdResetEvent CmdResetEvent;
    PFN_vkCmdWaitEvents CmdWaitEvents;
    PFN_vkCmdPipelineBarrier CmdPipelineBarrier;
    PFN_vkCmdBeginQuery CmdBeginQuery;
    PFN_vkCmdEndQuery CmdEndQuery;
    PFN_vkCmdResetQueryPool CmdResetQueryPool;
    PFN_vkCmdWriteTimestamp CmdWriteTimestamp;
    PFN_vkCmdInitAtomicCounters CmdInitAtomicCounters;
    PFN_vkCmdLoadAtomicCounters CmdLoadAtomicCounters;
    PFN_vkCmdSaveAtomicCounters CmdSaveAtomicCounters;
    PFN_vkCreateFramebuffer CreateFramebuffer;
    PFN_vkCreateRenderPass CreateRenderPass;
    PFN_vkCmdBeginRenderPass CmdBeginRenderPass;
    PFN_vkCmdEndRenderPass CmdEndRenderPass;
    PFN_vkDbgSetValidationLevel DbgSetValidationLevel;
    PFN_vkDbgRegisterMsgCallback DbgRegisterMsgCallback;
    PFN_vkDbgUnregisterMsgCallback DbgUnregisterMsgCallback;
    PFN_vkDbgSetMessageFilter DbgSetMessageFilter;
    PFN_vkDbgSetObjectTag DbgSetObjectTag;
    PFN_vkDbgSetGlobalOption DbgSetGlobalOption;
    PFN_vkDbgSetDeviceOption DbgSetDeviceOption;
    PFN_vkCmdDbgMarkerBegin CmdDbgMarkerBegin;
    PFN_vkCmdDbgMarkerEnd CmdDbgMarkerEnd;
#if defined(__linux__) || defined(XCB_NVIDIA)
    PFN_vkWsiX11AssociateConnection WsiX11AssociateConnection;
    PFN_vkWsiX11GetMSC WsiX11GetMSC;
    PFN_vkWsiX11CreatePresentableImage WsiX11CreatePresentableImage;
    PFN_vkWsiX11QueuePresent WsiX11QueuePresent;
#endif // WIN32
} VkLayerDispatchTable;

// LL node for tree of dbg callback functions
typedef struct _VK_LAYER_DBG_FUNCTION_NODE
{
    VK_DBG_MSG_CALLBACK_FUNCTION pfnMsgCallback;
    void *pUserData;
    struct _VK_LAYER_DBG_FUNCTION_NODE *pNext;
} VK_LAYER_DBG_FUNCTION_NODE;

typedef enum _VK_LAYER_DBG_ACTION
{
    VK_DBG_LAYER_ACTION_IGNORE = 0x0,
    VK_DBG_LAYER_ACTION_CALLBACK = 0x1,
    VK_DBG_LAYER_ACTION_LOG_MSG = 0x2,
    VK_DBG_LAYER_ACTION_BREAK = 0x4
} VK_LAYER_DBG_ACTION;

typedef enum _VK_LAYER_DBG_REPORT_LEVEL
{

    VK_DBG_LAYER_LEVEL_INFO = 0,
    VK_DBG_LAYER_LEVEL_WARN,
    VK_DBG_LAYER_LEVEL_PERF_WARN,
    VK_DBG_LAYER_LEVEL_ERROR,
    VK_DBG_LAYER_LEVEL_NONE,
} VK_LAYER_DBG_REPORT_LEVEL;
// ------------------------------------------------------------------------------------------------
// API functions