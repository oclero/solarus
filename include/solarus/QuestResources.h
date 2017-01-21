/*
 * Copyright (C) 2006-2016 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_QUEST_RESOURCE_H
#define SOLARUS_QUEST_RESOURCE_H

#include "solarus/Common.h"
#include "solarus/EnumInfo.h"
#include "solarus/lua/LuaData.h"
#include "solarus/ResourceType.h"
#include <iosfwd>
#include <map>
#include <string>

namespace Solarus {

template <>
struct SOLARUS_API EnumInfoTraits<ResourceType> {
  static const std::string pretty_name;

  static const EnumInfo<ResourceType>::names_type names;
};

/**
 * \brief Stores the resource list of a quest.
 *
 * This class basically stores the content of a resource list file
 * project_db.dat.
 * It does not create, remove or rename any resource file.
 */
class SOLARUS_API QuestResources : public LuaData {

  public:

    /**
     * Mapping of resource element ids to their description.
     */
    using ResourceMap = std::map<std::string, std::string>;

    QuestResources();

    void clear();

    bool exists(ResourceType resource_type, const std::string& id) const;
    const ResourceMap& get_elements(
        ResourceType resource_type
    ) const;
    ResourceMap& get_elements(
        ResourceType resource_type
    );

    bool add(
        ResourceType resource_type,
        const std::string& id,
        const std::string& description
    );
    bool remove(
        ResourceType resource_type,
        const std::string& id
    );
    bool rename(
        ResourceType resource_type,
        const std::string& old_id,
        const std::string& new_id
    );
    std::string get_description(
        ResourceType resource_type,
        const std::string& id
    ) const;
    bool set_description(
        ResourceType resource_type,
        const std::string& id,
        const std::string& description
    );

    virtual bool import_from_lua(lua_State* l) override;
    virtual bool export_to_lua(std::ostream& out) const override;

  private:

    std::map<ResourceType, ResourceMap> resource_maps;

};

}

#endif

