//
// Mani Admin Plugin
//
// Copyright (c) 2009 Giles Millward (Mani). All rights reserved.
//
// This file is part of ManiAdminPlugin.
//
// Mani Admin Plugin is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Mani Admin Plugin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Mani Admin Plugin.  If not, see <http://www.gnu.org/licenses/>.
//

//



#ifndef MANI_CHATTRIGGER_H
#define MANI_CHATTRIGGER_H

#define	MANI_CT_IGNORE	(0)
#define MANI_CT_IGNORE_STRING ("Ignore")

struct		chat_trigger_t
{
	char	say_command[512];
	int		trigger_type;
};

class ManiChatTriggers
{

public:
	ManiChatTriggers();
	~ManiChatTriggers();

	void		Load(void);
	void		LevelInit(void);
	bool		PlayerSay(player_t *player_ptr, const char *chat_string, bool teamonly, bool from_event);
	PLUGIN_RESULT	ProcessMaChatTriggers( int index,  bool svr_command,  int argc,  char *command_string,  char *target_string);

private:

	void		CleanUp(void);
	void		LoadData(void);
	bool		ProcessIgnore(player_t *player_ptr, const char *chat_string, bool teamonly, bool from_event);
	void		ProcessLoadIgnore(KeyValues *kv_parent_ptr);
	bool		FindString(const char *chat_string, chat_trigger_t **chat_trigger_ptr);
	void		DumpTriggerData( player_t *player_ptr,  bool svr_command,  chat_trigger_t *chat_trigger_ptr );

	chat_trigger_t	*chat_trigger_list;
	int				chat_trigger_list_size;

};

extern	ManiChatTriggers *gpManiChatTriggers;

#endif
