#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <wdlstring.h>
/**
 * \brief  a preset version number is used to handle preset versioning in the future,
 * it must be and increment of 1 for each new version necessiting a preset format change
 */
constexpr uint32_t CURRENT_PRESET_VERSION = 1;

class NeuralAmpModelerPreset
{
public:
  NeuralAmpModelerPreset(std::string name, std::string desc, std::string ampPath, std::string irPath,
                         std::vector<float> params);

  static const NeuralAmpModelerPreset* Deserialize(const WDL_String& presetPath, std::string& errorMessage);
  static bool  Serialize(const WDL_String& presetPath, const NeuralAmpModelerPreset& preset, std::string& errorMessage);

  [[nodiscard]] const std::string& Name() const { return _name; }
  [[nodiscard]] const std::string& Description() const { return _description; }
  [[nodiscard]] const std::string& AmpPath() const { return _amp; }
  [[nodiscard]] const std::string& IrPath() const { return _ir; }

  [[nodiscard]] const std::vector<float>& Params() const { return _params; }

  [[nodiscard]] uint32_t Version() const { return _version; }

protected:
  std::string _name;
  std::string _description;
  std::string _amp;
  std::string _ir;
  std::vector<float> _params;
  uint32_t _version;
};
