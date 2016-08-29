#ifndef _VE_DETECTION_H
#define _VE_DETECTION_H

#include "json.h"
#include "config.h"

namespace SandboxEvasion {
	class VEDetection {
	public:
		VEDetection(const json_tiny &j) : conf(j) {}
		virtual ~VEDetection() {};

		void CheckAll();
		virtual std::string GetReport() {
			return report;
		};

		std::string GetModuleName() const { return module_name; }

	protected:
		json_tiny conf;
		std::string module_name;
		std::string report;

		void CheckAllRegistryExists() const;
		void CheckAllRegistryValues() const;
		void CheckAllFilesExist() const;
		void CheckAllDevicesExists() const;
		void CheckAllProcessRunning() const;
		void CheckAllMacVendors() const;
		void CheckAllAdaptersName() const;
		virtual void CheckAllCustom() = 0;

		bool CheckRegKeyExists(const std::string &key_root, const std::string &key) const;
		bool CheckRegKeySubkeyContains(const std::string &key_root, const std::string &key, const std::string &subkey, const std::string &value) const;
		bool CheckFileExists(const file_name_t &file_name) const;
		bool CheckDeviceExists(const file_name_t &dev_name) const;
		bool CheckProcessIsRunning(const process_name_t &proc_name) const;
		bool CheckMacVendor(const std::string &ven_id) const;
		bool CheckAdapterName(const std::string &adapter_name) const;

		std::pair<std::string, std::string> GenerateReportEntry(const std::string &name, const json_tiny &j, bool detected) const;
	};
}

#endif // !_VM_DETECTION_H

