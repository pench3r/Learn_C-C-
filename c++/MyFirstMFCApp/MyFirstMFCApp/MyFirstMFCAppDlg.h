
// MyFirstMFCAppDlg.h: 头文件
//

#pragma once

#include "CMyListCtrlEx.h"
// CMyFirstMFCAppDlg 对话框
class CMyFirstMFCAppDlg : public CDialogEx
{
// 构造
public:
	CMyFirstMFCAppDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYFIRSTMFCAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void ShowProcessFromToolHelp();	// 使用tool help系列函数来获取
	void ShowProcessFromEnumProcess();  // 使用EnumProcess来获取
	void ShowProcessFromNtQuerySystemInfo(); // 使用NtQuerySysteminfo来获取
	void AutoSize(int nId, int x, int y);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList3(NMHDR *pNMHDR, LRESULT *pResult);
	CMyListCtrlEx m_ProcessList;
	afx_msg void OnBnClickedOk();
	CString m_selectListItem;
	DWORD m_selectListPid;
	long m_buttonRight2DlgDistance;
	long m_buttonBottom2DlgDistance;
	long m_listRight2DlgDistance;
	long m_listBottom2DlgDistance;
	long m_staticTop2DlgDistance;
	bool m_buttonSizeStoreFlag = false;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnPopupDisplaydll();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

typedef struct unicode_string_ {
	USHORT Length;
	USHORT MaximumLength;
	PWSTR  Buffer;
}UNICODE_STRING, *PUNICODE_STRING;

typedef long KPRIORITY;

typedef struct vm_counters_ {
	SIZE_T        PeakVirtualSize;
	SIZE_T        VirtualSize;
	ULONG         PageFaultCount;
	SIZE_T        PeakWorkingSetSize;
	SIZE_T        WorkingSetSize;
	SIZE_T        QuotaPeakPagedPoolUsage;
	SIZE_T        QuotaPagedPoolUsage;
	SIZE_T        QuotaPeakNonPagedPoolUsage;
	SIZE_T        QuotaNonPagedPoolUsage;
	SIZE_T        PagefileUsage;
	SIZE_T        PeakPagefileUsage;
}VM_COUNTERS;

typedef struct _CLIENT_ID
{
	DWORD        UniqueProcess;
	DWORD        UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

typedef struct _SYSTEM_THREAD_INFORMATION
{
	LARGE_INTEGER   KernelTime;
	LARGE_INTEGER   UserTime;
	LARGE_INTEGER   CreateTime;
	ULONG           WaitTime;
	PVOID           StartAddress;
	CLIENT_ID       ClientId;
	KPRIORITY       Priority;
	KPRIORITY       BasePriority;
	ULONG           ContextSwitchCount;
	LONG            State;// 状态,是THREAD_STATE枚举类型中的一个值
	LONG            WaitReason;//等待原因, KWAIT_REASON中的一个值
} SYSTEM_THREAD_INFORMATION, *PSYSTEM_THREAD_INFORMATION;

typedef struct system_process_information_ {
	ULONG            NextEntryDelta; // 指向下一个结构体的指针
	ULONG            ThreadCount; // 本进程的总线程数
	ULONG            Reserved1[6]; // 保留
	LARGE_INTEGER    CreateTime; // 进程的创建时间
	LARGE_INTEGER    UserTime; // 在用户层的使用时间
	LARGE_INTEGER    KernelTime; // 在内核层的使用时间
	UNICODE_STRING   ProcessName; // 进程名
	KPRIORITY        BasePriority; // 
	ULONG            ProcessId; // 进程ID
	ULONG            InheritedFromProcessId;
	ULONG            HandleCount; // 进程的句柄总数
	ULONG            Reserved2[2]; // 保留
	VM_COUNTERS      VmCounters;
	IO_COUNTERS      IoCounters;
	SYSTEM_THREAD_INFORMATION Threads[5]; // 子线程信息数组
}SYSTEM_PROCESS_INFORMATION, *PSYSTEM_PROCESS_INFORMATION;

typedef enum system_information_class_ {
	SystemBasicInformation,                // 0 Y N
		SystemProcessorInformation,            // 1 Y N
		SystemPerformanceInformation,        // 2 Y N
		SystemTimeOfDayInformation,            // 3 Y N
		SystemNotImplemented1,                // 4 Y N
		SystemProcessesAndThreadsInformation, // 5 Y N
		SystemCallCounts,                    // 6 Y N
		SystemConfigurationInformation,        // 7 Y N
		SystemProcessorTimes,                // 8 Y N
		SystemGlobalFlag,                    // 9 Y Y
		SystemNotImplemented2,                // 10 Y N
		SystemModuleInformation,            // 11 Y N
		SystemLockInformation,                // 12 Y N
		SystemNotImplemented3,                // 13 Y N
		SystemNotImplemented4,                // 14 Y N
		SystemNotImplemented5,                // 15 Y N
		SystemHandleInformation,            // 16 Y N
		SystemObjectInformation,            // 17 Y N
		SystemPagefileInformation,            // 18 Y N
		SystemInstructionEmulationCounts,    // 19 Y N
		SystemInvalidInfoClass1,            // 20
		SystemCacheInformation,                // 21 Y Y
		SystemPoolTagInformation,            // 22 Y N
		SystemProcessorStatistics,            // 23 Y N
		SystemDpcInformation,                // 24 Y Y
		SystemNotImplemented6,                // 25 Y N
		SystemLoadImage,                    // 26 N Y
		SystemUnloadImage,                    // 27 N Y
		SystemTimeAdjustment,                // 28 Y Y
		SystemNotImplemented7,                // 29 Y N
		SystemNotImplemented8,                // 30 Y N
		SystemNotImplemented9,                // 31 Y N
		SystemCrashDumpInformation,            // 32 Y N
		SystemExceptionInformation,            // 33 Y N
		SystemCrashDumpStateInformation,    // 34 Y Y/N
		SystemKernelDebuggerInformation,    // 35 Y N
		SystemContextSwitchInformation,        // 36 Y N
		SystemRegistryQuotaInformation,        // 37 Y Y
		SystemLoadAndCallImage,                // 38 N Y
		SystemPrioritySeparation,            // 39 N Y
		SystemNotImplemented10,                // 40 Y N
		SystemNotImplemented11,                // 41 Y N
		SystemInvalidInfoClass2,            // 42
		SystemInvalidInfoClass3,            // 43
		SystemTimeZoneInformation,            // 44 Y N
		SystemLookasideInformation,            // 45 Y N
		SystemSetTimeSlipEvent,                // 46 N Y
		SystemCreateSession,                // 47 N Y
		SystemDeleteSession,                // 48 N Y
		SystemInvalidInfoClass4,            // 49
		SystemRangeStartInformation,        // 50 Y N
		SystemVerifierInformation,            // 51 Y Y
		SystemAddVerifier,                    // 52 N Y
		SystemSessionProcessesInformation    // 53 Y N
}SYSTEM_INFORMATION_CLASS;

typedef LONG NTSTATUS;

// 这里需要注意函数的调用约定windows的函数调用都是_stdcall,C默认为_cdecl
typedef NTSTATUS (_stdcall *NtQueryFunc)(SYSTEM_INFORMATION_CLASS, PVOID, ULONG, PULONG);

// __kernel_entry NTSTATUS NtQuerySystemInformation(
//	IN SYSTEM_INFORMATION_CLASS SystemInformationClass,
//	OUT PVOID                   SystemInformation,
//	IN ULONG                    SystemInformationLength,
//	OUT PULONG ReturnLength     OPTIONAL
//);