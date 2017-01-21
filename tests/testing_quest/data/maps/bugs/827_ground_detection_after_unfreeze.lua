local map = ...
local game = map:get_game()

function map:on_opening_transition_finished()

  -- Freeze the hero.
  hero:freeze()
  assert_equal(hero:get_state(), "frozen")

  -- Make him jump while frozen.
  local movement = sol.movement.create("jump")
  movement:set_direction8(0)
  movement:set_distance(48)
  movement:start(hero, function()

    -- He arrived in deep water and should be in state plunging now.
    assert_equal(hero:get_state(), "plunging")

    -- Unfreeze the hero: he should now be plunging again.
    hero:unfreeze()
    assert_equal(hero:get_state(), "plunging")
    sol.main.exit()
  end)

end
