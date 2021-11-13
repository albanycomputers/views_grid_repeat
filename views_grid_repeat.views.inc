<?php
/**
 * @file
 * Provide views data and handlers for views_grid_repeat module.
 */

/**
 * Implements hook_views_plugins().
 */
function views_grid_repeat_views_plugins() {
  return array(
    'style' => array(
      'flexviews' => array(
        'title' => t('CSS3 Grid Fit or Fill'),
        'handler' => 'views_plugin_style_views_grid_repeat',
        'help' => t("Display Views content in A CSS3 Grid"),
        'theme' => 'views_view_views_grid_repeat',
        'type' => 'normal',
        'path' => backdrop_get_path('module', 'views_grid_repeat'),
        'theme path' => backdrop_get_path('module', 'views_grid_repeat'),
        'uses row plugin' => TRUE,
        'uses row class' => TRUE,
        'uses grouping' => FALSE,
        'uses options' => TRUE,
      ),
    ),
  );
}

